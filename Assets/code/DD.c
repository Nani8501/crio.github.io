
#include<stdio.h> 
#include<stdbool.h>

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to delete the first node from the linked list
struct Node* deleteFirstNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("First node deleted successfully.\n");
    return head;
}

// Function to delete the last node from the linked list
struct Node* deleteLastNode(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    printf("Last node deleted successfully.\n");
    return head;
}

// Function to delete a node with a given key from the linked list
struct Node* deleteNode(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
    } else {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
        printf("Node with data %d deleted successfully.\n", key);
    }
    return head;
}

// Function to display the doubly linked list
void displayDoublyLinkedList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create and initialize nodes for the doubly linked list
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->prev = NULL;
    head->next = second;

    second->data = 2;
    second->prev = head;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = NULL;

    printf("Original Doubly Linked List: ");
    displayDoublyLinkedList(head);

    // Perform deletion operations
    head = deleteFirstNode(head);
    displayDoublyLinkedList(head);

    head = deleteLastNode(head);
    displayDoublyLinkedList(head);

    head = deleteNode(head, 2);
    displayDoublyLinkedList(head);

    return 0;
}
              
            
