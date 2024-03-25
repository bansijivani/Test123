#include <stdio.h>
#include <stdlib.h> // For malloc

int main() {
    int *ptr = malloc(sizeof(int)); // Allocate memory for an integer
    if (ptr == NULL) { // Always check if memory allocation was successful
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    *ptr = 10; // Dereference `ptr` to store the value 10

    printf("Value: %d\n", *ptr); // Print the value stored at `ptr`

    free(ptr); // Free the allocated memory
    return 0;
}
