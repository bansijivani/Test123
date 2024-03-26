#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    char a;      // 1 byte
    // Implicit padding (3 bytes) might be added here for alignment
    int b;       // 4 bytes
} MyStruct;

int main() {
    // Allocate memory for an array of MyStruct
    size_t numElements = 5;
    unsigned char *buffer = (unsigned char *)malloc(numElements * sizeof(MyStruct) + 1);
    
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // Intentionally misalign the starting address
    MyStruct *array = (MyStruct *)(buffer + 1);
    
    // Initialize the array
    for (size_t i = 0; i < numElements; i++) {
        array[i].a = 'a' + i;
        array[i].b = i * i;
    }
    
    // Access and print the array elements
    for (size_t i = 0; i < numElements; i++) {
        printf("Element %zu: a = %c, b = %d\n", i, array[i].a, array[i].b);
    }
    
    // Free the allocated memory
    free(buffer);
    
    return 0;
}
