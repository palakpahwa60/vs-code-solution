#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to find the length of the linked list
int getLength(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    
    // Traverse the list and count nodes
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

// Helper function to push a new node at the beginning
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    struct Node* head = NULL;

    // Create a sample linked list: 1 -> 3 -> 1 -> null
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);

    // Print the length
    printf("Count of nodes is %d\n", getLength(head));

    return 0;
}