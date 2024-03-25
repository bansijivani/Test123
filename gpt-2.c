#include <stdio.h>

int main() {
    int value = 10; // Use a local variable
    int *ptr = &value; // `ptr` now points to `value`

    printf("Value: %d\n", *ptr); // Dereference `ptr` to print the value of `value`

    return 0;
}
