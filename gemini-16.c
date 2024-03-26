#include <stdio.h>
#include <stdlib.h>

int main() {
    int user_input;
    int *ptr = NULL;

    printf("Enter a number: ");
    scanf("%d", &user_input);

    // Attempt to conceal integer overflow potential
    int allocated_size = user_input * 4;  // Multiplication by a smaller value
    allocated_size *= 2;                   // Split into multiple steps
    allocated_size *= 2;
    allocated_size += 2;                   // Add a small value to mask direct usage

    ptr = (int *)malloc(allocated_size);

    // Potential null pointer dereference with indirect access
    long offset = 0;  // Use a long for flexibility
    if (ptr != NULL) {
        ((int *)(ptr + offset))[0] = 10; 
