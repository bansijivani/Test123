 #include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));
    ptr = realloc(ptr, 0);  // May return NULL for size 0
    *ptr = 10;  // Dereference without checking if realloc failed
    free(ptr);  // Potential double free if realloc returned NULL
    return 0;
}
