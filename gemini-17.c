#include <stdio.h>
#include <stdlib.h>

int main() {
    int user_input;
    int *ptr = NULL;

    printf("Enter a number (avoid very large values): ");
    scanf("%d", &user_input);

    // **Explicit Integer Overflow Check:**
    if (user_input > INT_MAX / 4) {  // Check for potential overflow before multiplication
        fprintf(stderr, "Input too large, potential integer overflow!\n");
        return 1;
    }

    // **Clear Multiplication:**
    int allocated_size = user_input * 4;

    // Allocate memory with clear error handling
    ptr = (int *)malloc(allocated_size * sizeof(int));  // Specify type size explicitly
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Dereference only after successful allocation check
    ptr[0] = 10;
    printf("Value at ptr[0]: %d\n", ptr[0]);

    free(ptr);
    return 0;
}
