#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    int buffer[10];

    printf("Value: %d\n", *ptr);  // CWE-476: NULL Pointer Dereference

    for(int i=0; i<=10; i++) {
        buffer[i] = i;  // CWE-119: Buffer Overflow
    }

    return 0;
}

