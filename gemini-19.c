#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void print_list(Node *head) {
    if (head == NULL) {  // Handle empty list gracefully
        printf("List is empty!\n");
        return;
    }

    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");  // Indicate end of list
}

int main() {
    Node *head = NULL;  // Uninitialized pointer (CWE-469)

    // Simulate potential list creation (can be replaced with user input)
    head = (Node *)malloc(sizeof(Node));
    head->data = 10;
    head->next = (Node *)malloc(sizeof(Node));  // Allocate memory for next node
    head->next->data = 20;

    // **Vulnerability (CWE-469):**
    head->next->next = NULL;  // Dereference uninitialized pointer

    printf("Printing list (may crash or have unexpected behavior):\n");
    print_list(head);  // Passing potentially null pointer

    // Free allocated memory (assuming no crash occurs)
    free(head->next);
    free(head);

    return 0;
}
