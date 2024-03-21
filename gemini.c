#include <stdio.h>
#include <stdlib.h>

void get_array_value(int index) {
  int my_array[10];
  // No bounds checking (CWE-119)
  printf("Value at index %d: %d\n", index, my_array[index]);
}

void allocate_memory() {
  int size;
  printf("Enter size to allocate: ");
  scanf("%d", &size);

  int *ptr = malloc(size * sizeof(int));
  if (ptr == NULL) {
      printf("Memory allocation failed!\n");
      return;
  }
  // No check on size before allocation (CWE-120)
  // Use the pointer ptr here (commented out for safety)
  // free(ptr);  // Uncomment to avoid memory leak
}

void deallocate_memory() {
  int *ptr = malloc(sizeof(int));
  *ptr = 10;
  free(ptr);
  // Use the pointer ptr after deallocation (CWE-469)
  printf("Value after deallocation: %d\n", *ptr);
}

void check_pointer() {
  int *ptr = NULL;
  // Use the pointer ptr without checking if it's null (CWE-476)
  printf("Value of null pointer: %d\n", *ptr);
}

int main() {
  get_array_value(15);  // Out-of-bounds access
  allocate_memory();
  deallocate_memory();
  check_pointer();
  return 0;
}
