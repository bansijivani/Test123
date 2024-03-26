#include <stdio.h>
#include <stdint.h>

typedef struct {
    int id;
    char name[20];
    float balance;
} Account;

void processAccount(void *ptr) {
    // Improper casting leading to CWE-469 vulnerability
    char *charPtr = (char *)ptr;
    printf("Processing data at charPtr: %s\n", charPtr);
    
    // Assuming it was a pointer to char, but actually it points to an Account struct
    printf("First character of name: %c\n", *charPtr);
}

int main() {
    Account acc = {1, "John Doe", 1000.50f};

    // Proper way to handle, but the function misuse leads to vulnerability
    processAccount(&acc);

    return 0;
}
