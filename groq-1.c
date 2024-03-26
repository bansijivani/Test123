#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable_function(char *input) {
 char buffer[10];

 // CWE 119: Improper Restriction of Operations within the Bounds of a Memory Buffer
 strcpy(buffer, input);

 // CWE 476: NULL Pointer Dereference
 if (input == NULL) {
 printf("Error: input is NULL\n");
 } else {
 printf("Input: %s\n", buffer);
 }
}

int main(int argc, char *argv[]) {
 if (argc < 2) {
 printf("Usage: %s <input>\n", argv[0]);
 return 1;
 }

 vulnerable_function(argv[1]);

 return 0;
}
