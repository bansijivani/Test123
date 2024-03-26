#include <stdio.h>

int main() {
    int *ptr;  // Uninitialized pointer

    // Direct Dereference (CWE-469)
    *ptr = 10;  // Attempt to modify the value at an unknown memory location

    printf("Value: %d\n", *ptr);  // Undefined behavior (may crash)

    return 0;
}
