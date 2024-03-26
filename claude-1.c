#include <stdio.h>
#include <stdlib.h>

// Dummy data structures and types
typedef int IntSet;

typedef struct {
    IntSet* consumption;
} ScalarDependenceEntry;

typedef struct {
    IntSet scalar_def;
} DFInfo;

typedef struct {
    ScalarDependenceEntry* scalar_dependence_entry;
    DFInfo* df_info;
} Block;

// Dummy functions
void construct_IntSet(IntSet* set, IntSet range) {
    *set = range;
}

IntSet range_IntSet(IntSet set) {
    return set;
}

// The given code snippet
IntSet* get_scalar_consumption(Block* bpt) {
    if (bpt != NULL && bpt->scalar_dependence_entry != NULL) {
        if (bpt->scalar_dependence_entry->consumption != NULL) {
            return bpt->scalar_dependence_entry->consumption;
        } else {
            IntSet set;
            construct_IntSet(&set, range_IntSet(bpt->df_info->scalar_def));
            return malloc(sizeof(IntSet));
        }
    } else {
        return NULL;
    }
}

int main() {
    // Create dummy data
    Block block;
    ScalarDependenceEntry entry;
    DFInfo info;

    info.scalar_def = 42;
    entry.consumption = NULL;
    block.scalar_dependence_entry = &entry;
    block.df_info = &info;

    IntSet* result = get_scalar_consumption(&block);
    if (result != NULL) {
        printf("Scalar consumption: %d\n", *result);
        free(result);
    } else {
        printf("Scalar consumption: NULL\n");
    }

    return 0;
}
