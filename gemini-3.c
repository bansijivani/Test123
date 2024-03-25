#include <stdio.h>

int main() {
  int *ptr = NULL;
  *ptr = 10; // Dereference null pointer

  printf("Value: %d\n", *ptr); // Undefined behavior

  return 0;
}
