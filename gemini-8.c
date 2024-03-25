#include <stdio.h>

typedef struct {
    int value;
} MyStruct;

int main() {
    MyStruct *ptr = NULL;
    int val = ptr->value;  // Dereference null struct member
    printf("Value: %d\n", val);
    return 0;
}
