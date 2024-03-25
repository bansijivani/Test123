#include <stdio.h>
#include <stdlib.h>

void *allocate_memory(int size) {
    void *ptr = malloc(size);
    // No error handling for malloc failure
    return ptr;
}

int main() {
    void *ptr = allocate_memory(100);
    *ptr = 80;  // Dereference without checking for potential malloc failure
    printf("Value: %d\n", *(int *)ptr);  // Assuming integer allocation
    return 0;
}
