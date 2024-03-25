#include <stdio.h>

int main() {
    int *ptr;  // Uninitialized pointer
    *ptr = 10;  // Dereference without checking for null
    printf("Value: %d\n", *ptr);
    return 0;
}
