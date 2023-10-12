*/
    PRIYANSHI SINGH
    IT_57
    BATCH C
    
/*#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure for the deque
struct Deque {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the deque
void initialize(struct Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Function to check if the deque is empty
int isEmpty(struct Deque deque) {
    return deque.front == -1;
}

// Function to check if the deque is full
int isFull(struct Deque deque) {
    return (deque.front == 0 && deque.rear == MAX_SIZE - 1) ||
           (deque.front == deque.rear + 1);
}

// Function to add an element at the front of the deque
void insertFront(struct Deque *deque, int value) {
    if (isFull(*deque)) {
        printf("Deque is full. Cannot insert at the front.\n");
    } else {
        if (deque->front == -1) {
            deque->front = deque->rear = 0;
        } else if (deque->front == 0) {
            deque->front = MAX_SIZE - 1;
        } else {
            deque->front--;
        }
        deque->items[deque->front] = value;
        printf("%d inserted at the front of the deque.\n", value);
    }
}

// Function to add an element at the rear of the deque
void insertRear(struct Deque *deque, int value) {
    if (isFull(*deque)) {
        printf("Deque is full. Cannot insert at the rear.\n");
    } else {
        if (deque->front == -1) {
            deque->front = deque->rear = 0;
        } else if (deque->rear == MAX_SIZE - 1) {
            deque->rear = 0;
        } else {
            deque->rear++;
        }
        deque->items[deque->rear] = value;
        printf("%d inserted at the rear of the deque.\n", value);
    }
}

// Function to remove an element from the front of the deque
int deleteFront(struct Deque *deque) {
    int deletedItem;

    if (isEmpty(*deque)) {
        printf("Deque is empty. Cannot delete from the front.\n");
        return -1; // Return an error value
    } else {
        deletedItem = deque->items[deque->front];
        if (deque->front == deque->rear) {
            deque->front = deque->rear = -1;
        } else if (deque->front == MAX_SIZE - 1) {
            deque->front = 0;
        } else {
            deque->front++;
        }
        return deletedItem;
    }
}

// Function to remove an element from the rear of the deque
int deleteRear(struct Deque *deque) {
    int deletedItem;

    if (isEmpty(*deque)) {
        printf("Deque is empty. Cannot delete from the rear.\n");
        return -1; // Return an error value
    } else {
        deletedItem = deque->items[deque->rear];
        if (deque->front == deque->rear) {
            deque->front = deque->rear = -1;
        } else if (deque->rear == 0) {
            deque->rear = MAX_SIZE - 1;
        } else {
            deque->rear--;
        }
        return deletedItem;
    }
}

// Function to display the elements of the deque
void display(struct Deque deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = deque.front;
        do {
            printf("%d ", deque.items[i]);
            if (i == MAX_SIZE - 1) {
                i = 0;
            } else {
                i++;
            }
        } while (i != (deque.rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    struct Deque deque;
    initialize(&deque);

    insertFront(&deque, 1);
    insertRear(&deque, 2);
    insertFront(&deque, 3);
    insertRear(&deque, 4);

    display(deque);

    int deletedValue = deleteFront(&deque);
    if (deletedValue != -1) {
        printf("Deleted item from the front: %d\n", deletedValue);
    }

    deletedValue = deleteRear(&deque);
    if (deletedValue != -1) {
        printf("Deleted item from the rear: %d\n", deletedValue);
    }

    display(deque);

    return 0;
}
