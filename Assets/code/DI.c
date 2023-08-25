
#include 
#include 

// Structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node with data %d inserted at the beginning.\n", data);
    return head;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node with data %d inserted at the end.\n", data);
    return head;
}

// Function to insert a node after a given node in the linked list
struct Node* insertAfterNode(struct Node* head, int data, int key) {
    if (head == NULL) {
        printf("List is empty. Unable to insert.\n");
        return NULL;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
    } else {
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
        printf("Node with data %d inserted after node with data %d.\n", data, key);
    }
    return head;
}

// Function to insert a node before a given node in the linked list
struct Node* insertBeforeNode(struct Node* head, int data, int key) {
    if (head == NULL) {
        printf("List is empty. Unable to insert.\n");
        return NULL;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with data %d not found.\n", key);
    } else {
        newNode->prev = temp->prev;
        if (temp->prev != NULL) {
            temp->prev->next = newNode;
        } else {
            head = newNode;
        }
        newNode->next = temp;
        temp->prev = newNode;
        printf("Node with data %d inserted before node with data %d.\n", data, key);
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
    struct Node* head = NULL;
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    printf("Original Doubly Linked List: ");
    displayDoublyLinkedList(head);

    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    printf("Updated Doubly Linked List after insertions at the beginning and end: ");
    displayDoublyLinkedList(head);

    head = insertAfterNode(head, 6, 3);

    printf("Updated Doubly Linked List after insertion after node with data 3: ");
    displayDoublyLinkedList(head);

    head = insertBeforeNode(head, 7, 4);

    printf("Updated Doubly Linked List after insertion before node with data 4: ");
    displayDoublyLinkedList(head);

    return 0;
}
              
            
