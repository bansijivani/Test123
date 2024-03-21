#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[10];
    char* ptr = NULL;

    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Allocate memory for the string
    ptr = (char*)malloc(strlen(buffer) + 1);
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Copy the string into the allocated memory
    strcpy(ptr, buffer);

    // Print the copied string
    printf("Copied string: %s\n", ptr);

    // Free the allocated memory
    free(ptr);

    return 0;
}
