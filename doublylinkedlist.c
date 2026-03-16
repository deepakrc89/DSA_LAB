#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

// Function prototypes
void insert(int data);
void traverseForward();
void traverseBackward();
void insert_at_end(int data);
void insert_after_value(int data, int value);
void delete_by_value(int value);
void delete_at_end();
void delete_at_beginning();

// Insert at beginning
void insert(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Traverse forward
void traverseForward() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Traverse backward
void traverseBackward() {
    Node* temp = head;

    if (head == NULL) {
        printf("List not found\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Insert at end
void insert_at_end(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after a given value
void insert_after_value(int data, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {
        printf("List is empty\n");
        free(newNode);
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Delete by value
void delete_by_value(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

// Delete at end
void delete_at_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;

    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
}

// Delete at beginning
void delete_at_beginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Main function
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printf("Forward Traversal: ");
    traverseForward();
    printf("Backward Traversal: ");
    traverseBackward();

    insert_at_end(60);
    printf("After inserting 60 at end: ");
    traverseForward();

    insert_after_value(25, 30); // insert 25 after value 30
    printf("After inserting 25 after 30: ");
    traverseForward();

    delete_by_value(40); // delete node with value 40
    printf("After deleting node with value 40: ");
    traverseForward();

    delete_at_end();
    printf("After deleting at end: ");
    traverseForward();

    delete_at_beginning();
    printf("After deleting at beginning: ");
    traverseForward();

    return 0;
}

//output:

Forward Traversal: 50 <-> 40 <-> 30 <-> 20 <-> 10 <-> NULL
Backward Traversal: 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL
After inserting 60 at end: 50 <-> 40 <-> 30 <-> 20 <-> 10 <-> 60 <-> NULL
After inserting 25 after 30: 50 <-> 40 <-> 30 <-> 25 <-> 20 <-> 10 <-> 60 <-> NULL
After deleting node with value 40: 50 <-> 30 <-> 25 <-> 20 <-> 10 <-> 60 <-> NULL
After deleting at end: 50 <-> 30 <-> 25 <-> 20 <-> 10 <-> NULL
After deleting at beginning: 30 <-> 25 <-> 20 <-> 10 <-> NULL


=== Code Execution Successful ===

//*