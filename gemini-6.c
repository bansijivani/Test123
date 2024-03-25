#include <stdio.h>

int *get_pointer() {
    return NULL;  // Function might return NULL
}

int main() {
    int *ptr = get_pointer();
    *ptr = 20;  // Dereference without checking if get_pointer returned NULL
    printf("Value: %d\n", *ptr);
    return 0;
}
