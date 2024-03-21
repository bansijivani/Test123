#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strncpy to avoid buffer overflows

void get_array_value(int index) {
  int my_array[10];
  // Check if index is within bounds before accessing
  if (index >= 0 && index < sizeof(my_array) / sizeof(my_array[0])) {
    printf("Value at index %d: %d\n", index, my_array[index]);
  } else {
    printf("Error: Index out of bounds!\n");
  }
}

void allocate_memory() {
  int size;
  printf("Enter size to allocate (positive integer): ");
  scanf("%d", &size);

  if (size <= 0) {
      printf("Invalid size! Enter a positive integer.\n");
      return;
  }

  int *ptr = malloc(size * sizeof(int));
  if (ptr == NULL) {
      printf("Memory allocation failed!\n");
      return;
  }
  // Use the pointer ptr here (commented out for example)
  // free(ptr);  // Uncomment to avoid memory leak
}

void deallocate_memory() {
  int *ptr = malloc(sizeof(int));
  *ptr = 10;
  free(ptr);  // Free the memory before using it
  // Don't use the pointer ptr after deallocation
}

void check_pointer() {
  int *ptr = NULL;
  // Check if the pointer is null before dereferencing
  if (ptr != NULL) {
    printf("Value of ptr: %d\n", *ptr);  // Not recommended to use a null pointer even after check
  } else {
    printf("ptr is a null pointer!\n");
  }
}

int main() {
  get_array_value(5);  // Valid access
  allocate_memory();
  deallocate_memory();
  check_pointer();  // Checking a null pointer (safe now)
  return 0;
}
