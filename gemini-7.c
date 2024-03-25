#include <stdio.h>

void use_pointer(int *ptr) {
    *ptr = 30;  // Dereference without checking if ptr is null (callee's check)
}

int main() {
    int *ptr = NULL;
    use_pointer(ptr);
    return 0;
}
