#include <stdio.h>

int *global_ptr;  // Global pointer declared but not initialized

int main() {
    *global_ptr = 70;  // Dereference uninitialized global pointer
    printf("Value: %d\n", *global_ptr);
    return 0;
}
