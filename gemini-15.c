#include <stdio.h>
#include <stdlib.h>

int main() {
    int user_input;
    int *ptr = NULL;

    printf("Enter a number: ");
    scanf("%d", &user_input);

    // Potential Integer Overflow (CWE-119)
    int allocated_size = user_input * 10;  // Multiplication might overflow

    ptr = (int *)malloc(allocated_size);  // Allocate memory based on potentially invalid size

    // Potential Null Pointer Dereference (CWE-476)
    if (ptr != NULL) {
        ptr[0] = 10;  // Dereference without checking if allocation was successful
        printf("Value at ptr[0]: %d\n", ptr[0]);
    } else {
        fprintf(stderr, "Memory allocation failed!\n");
    }

    free(ptr);  // Free memory (safe even if allocation failed due to null check)
    return 0;
}
