#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node helper
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 1. Insertion at the Beginning
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    
    // Make the next of the new node point to the current head
    newNode->next = *head_ref;
    
    // Move the head to point to the new node
    *head_ref = newNode;
}

// 2. Insertion at the End
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    
    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    
    // Otherwise, traverse to the last node
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Change the next pointer of the last node to the new node
    last->next = newNode;
}

// 3. Insertion at a Specific Position (1-based index)
void insertAtPosition(struct Node** head_ref, int position, int data) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    // If inserting at the first position, call the beginning function
    if (position == 1) {
        insertAtBeginning(head_ref, data);
        return;
    }

    struct Node* temp = *head_ref;
    // Traverse to the node right before the desired position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If position is out of bounds
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    struct Node* newNode = createNode(data);
    // Point new node's next to the target node's upcoming sequence
    newNode->next = temp->next;
    // Link the previous node to the new node
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Driver code
int main() {
    struct Node* head = NULL; // Initialize empty list

    printf("Inserting 10 and 20 at the end:\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    printList(head); // Output: 10 -> 20 -> NULL

    printf("\nInserting 5 at the beginning:\n");
    insertAtBeginning(&head, 5);
    printList(head); // Output: 5 -> 10 -> 20 -> NULL

    printf("\nInserting 15 at position 3:\n");
    insertAtPosition(&head, 3, 15);
    printList(head); // Output: 5 -> 10 -> 15 -> 20 -> NULL

    return 0;
}
