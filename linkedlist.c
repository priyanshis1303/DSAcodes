#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("Inserted %d into the linked list.\n", value);
}

// Function to delete a node with a given value from the linked list
void delete(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Linked list is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("%d not found in the linked list. Cannot delete.\n", value);
    } else {
        if (prev == NULL) {
            *head = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        printf("Deleted %d from the linked list.\n", value);
    }
}

// Function to display the elements of the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
    } else {
        printf("Linked list elements: ");
        struct Node* current = head;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

// Function to search for a value in the linked list
int search(struct Node* head, int value) {
    int position = 1;
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1; // Value not found
}

int main() {
    struct Node* head = NULL;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    display(head);

    int searchValue = 3;
    int result = search(head, searchValue);
    if (result != -1) {
        printf("%d found at position %d in the linked list.\n", searchValue, result);
    } else {
        printf("%d not found in the linked list.\n", searchValue);
    }

    delete(&head, 3);
    delete(&head, 6);

    display(head);

    return 0;
}
