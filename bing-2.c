#include <stdio.h>
#include <string.h>

int main() {
    char buffer[10];

    // Simulate receiving larger input from user
    char *input = "This string is longer than 10 characters.";

    strcpy(buffer, input);  // CWE-119: Buffer Overflow

    printf("Buffer: %s\n", buffer);

    return 0;
}
