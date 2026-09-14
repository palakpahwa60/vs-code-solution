#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// 1. Function to delete the first node (Head)
void deleteAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is already empty.\n");
        return;
    }
    
    struct Node* temp = *head_ref; // Keep track of the old head
    *head_ref = (*head_ref)->next; // Move head to the next node
    free(temp);                    // Deallocate old head memory
    printf("First node deleted successfully.\n");
}

// 2. Function to delete the last node (Tail)
void deleteAtEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is already empty.\n");
        return;
    }
    
    struct Node* temp = *head_ref;
    
    // If there is only one node in the list
    if (temp->next == NULL) {
        *head_ref = NULL;
        free(temp);
        printf("Last node deleted successfully.\n");
        return;
    }
    
    // Traverse to find the second-to-last node
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = NULL; // Disconnect the last node
    free(temp);        // Deallocate last node memory
    printf("Last node deleted successfully.\n");
}

// 3. Function to delete a node at a given position (1-based index)
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is already empty.\n");
        return;
    }
    
    struct Node* temp = *head_ref;
    
    // If position is 1, it's a deletion at the beginning
    if (position == 1) {
        *head_ref = temp->next;
        free(temp);
        printf("Node at position %d deleted.\n", position);
        return;
    }
    
    struct Node* prev = NULL;
    // Traverse to find the node to be deleted
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    // If position is greater than the number of nodes
    if (temp == NULL) {
        printf("Position %d is out of range.\n", position);
        return;
    }
    
    prev->next = temp->next; // Unlink the node from the list
    free(temp);              // Free memory
    printf("Node at position %d deleted.\n", position);
}

// Helper function to insert a node at the beginning (for setup)
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Helper function to print the linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

