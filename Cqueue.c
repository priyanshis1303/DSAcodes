/*
   PRIYANSHI SINGH
   IT_57
   BATCH C
*/
#include<stdio.h>

#define MAX_SIZE 5

// Structure for the circular queue
struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

// Function to initialize the circular queue
void initialize(struct CircularQueue *cq) {
    cq->front = cq->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue cq) {
    return cq.front == -1;
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue cq) {
    return (cq.front == 0 && cq.rear == MAX_SIZE - 1) || (cq.front == cq.rear + 1);
}

// Function to add an element to the circular queue
void enqueue(struct CircularQueue *cq, int value) {
    if (isFull(*cq)) {
        printf("Queue is full. Cannot enqueue %d.\n", value);
    } else {
        if (cq->front == -1) {
            cq->front = cq->rear = 0;
        } else if (cq->rear == MAX_SIZE - 1) {
            cq->rear = 0;
        } else {
            cq->rear++;
        }
        cq->items[cq->rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue *cq) {
    int deletedItem;

    if (isEmpty(*cq)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return an error value
    } else {
        deletedItem = cq->items[cq->front];
        if (cq->front == cq->rear) {
            cq->front = cq->rear = -1;
        } else if (cq->front == MAX_SIZE - 1) {
            cq->front = 0;
        } else {
            cq->front++;
        }
        return deletedItem;
    }
}

// Function to display the elements of the circular queue
void display(struct CircularQueue cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        int i = cq.front;
        do {
            printf("%d ", cq.items[i]);
            if (i == MAX_SIZE - 1) {
                i = 0;
            } else {
                i++;
            }
        } while (i != (cq.rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    struct CircularQueue cq;
    initialize(&cq);

    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);
    enqueue(&cq, 4);
    enqueue(&cq, 5);

    display(cq);

    int deletedValue = dequeue(&cq);
    if (deletedValue != -1) {
        printf("Dequeued item: %d\n", deletedValue);
    }

    enqueue(&cq, 6);
    display(cq);

    return 0;
}
