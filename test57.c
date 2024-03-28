#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define CHIRP_PATH_MAX 256

struct hash_table {
    // Define your hash table structure here
};

struct chirp_dir {
    // Define your chirp_dir structure here
};

struct chirp_dirent {
    // Define your chirp_dirent structure here
};

struct chirp_audit {
    char name[CHIRP_PATH_MAX];
    int ndirs;
    int nfiles;
    int nbytes;
};

int get_directory_owner(const char *path, char *owner) {
    // Implement your get_directory_owner function here
    return 0;
}

void debug(int level, const char *format, ...) {
    // Implement your debug function here
}

void hash_table_insert(struct hash_table *table, const char *key, struct chirp_audit *entry) {
    // Implement your hash_table_insert function here
}

struct chirp_audit *hash_table_lookup(struct hash_table *table, const char *key) {
    // Implement your hash_table_lookup function here
    return NULL;
}

void chirp_audit_recursive(const char *path, struct hash_table *table) {
    struct chirp_dir *dir;
    struct chirp_dirent *d;
    char subpath[CHIRP_PATH_MAX];
    char owner[CHIRP_PATH_MAX];
    struct chirp_audit *entry;
    int result;

    result = get_directory_owner(path, owner);
    if (result < 0)
        strcpy(owner, "unknown");

    entry = hash_table_lookup(table, owner);
    if (!entry) {
        entry = malloc(sizeof(*entry));
        memset(entry, 0, sizeof(*entry));
        strcpy(entry->name, owner);
        hash_table_insert(table, owner, entry);
    }

    entry->ndirs++;
    dir = cfs->opendir(path);
    if (!dir) {
        debug(D_LOCAL, "audit: couldn't enter %s: %s", path, strerror(errno));
        return;
    }

    while ((d = cfs->readdir(dir))) {
        if (!strcmp(d->name, "."))
            continue;
        if (!strcmp(d->name, ".."))
            continue;
        if (!strncmp(d->name, ".__", 3))
            continue;
        if (!strncmp(d->name, ".__", 3))
            continue;

        sprintf(subpath, "%s/%s", path, d->name);

        if (S_ISDIR(d->info.cst_mode)) {
            chirp_audit_recursive(subpath, table);
        } else {
            entry->nfiles++;
            entry->nbytes += d->info.cst_size;
        }
    }

    cfs->closedir(dir);
}

int main() {
    // Define and initialize your hash table here
    struct hash_table table;
    // Initialize your hash table here

    const char *path = "/path/to/directory";
    chirp_audit_recursive(path, &table);

    // Print or process the audit results here

    return 0;
}
