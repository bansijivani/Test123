#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));
    *ptr = 50;
    free(ptr);  // Memory freed
    *ptr = 60;  // Dereference freed memory
    printf("Value: %d\n", *ptr);  // Undefined behavior
    return 0;
}
