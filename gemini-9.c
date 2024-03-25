#include <stdio.h>

int main() {
    int arr[5];
    int *ptr = &arr[10];  // Pointer points beyond array bounds
    *ptr = 40;  // Dereference out-of-bounds memory
    printf("Value: %d\n", *ptr);
    return 0;
}
