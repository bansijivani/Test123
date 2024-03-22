mca_common_sm_init(ompi_proc_t **procs,
                   size_t num_procs,
                   size_t size,
                   char *file_name,
                   size_t size_ctl_structure,
                   size_t data_seg_alignment) {
/* indicates whether or not I'm the lowest named process */
bool lowest_local_proc = false;
mca_common_sm_module_t *map = NULL;
size_t num_local_procs = 0;
opal_shmem_ds_t *seg_meta = NULL;

if (OMPI_SUCCESS != mca_common_sm_local_proc_reorder(procs, num_procs, &num_local_procs)) {
   return NULL;
}

/* If there are less than 2 local processes, there's nothing to do. */
if (num_local_procs < 2) {
   return NULL;
}

if (NULL == (seg_meta = (opal_shmem_ds_t *)malloc(sizeof(*seg_meta)))) {
   /* Out of resources - just bail */
   return NULL;
}

/* Determine whether or not I am the lowest local process */
lowest_local_proc = (0 == ompi_rte_compare_name_fields(OMPI_RTE_CMP_ALL, OMPI_PROC_MY_NAME, &(procs[0]->proc_name)));

/* If I am the lowest rank in the group, I will create the shared memory backing store */
if (lowest_local_proc) {
   if (OPAL_SUCCESS == opal_shmem_segment_create(seg_meta, file_name, size)) {
       map = attach_and_init(seg_meta, size, size_ctl_structure, data_seg_alignment, true);
       if (NULL == map) {
           /* Fail!
            * Only invalidate the shmem_ds to inform other processes of failure.
            */
           OPAL_SHMEM_DS_INVALIDATE(seg_meta);
       }
   }
}

/* Send shmem info to the rest of the local procs. */
if (OMPI_SUCCESS != mca_common_sm_rml_info_bcast(seg_meta, procs, num_local_procs, OMPI_RML_TAG_SM_BACK_FILE_CREATED, lowest_local_proc, file_name)) {
   goto out;
}

/* Handle valid shmem_ds (lowest process initialized segment successfully) */
if (OPAL_SHMEM_DS_IS_VALID(seg_meta)) {
   if (!lowest_local_proc) {
       map = attach_and_init(seg_meta, 0, size_ctl_structure, data_seg_alignment, false);
   } else {
       /* Wait for other processes to attach, then unlink */
       while (num_local_procs > map->module_seg->seg_num_procs_inited) {
           opal_atomic_rmb();
       }
       opal_shmem_unlink(seg_meta);
   }
}

out:
if (NULL != seg_meta) {
   free(seg_meta);
}

return map;
}
