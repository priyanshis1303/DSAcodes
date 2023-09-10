#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the stack
struct Stack {
    struct Node* top;
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack stack) {
    return stack.top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push.\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(*stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; // Return an error value
    }
    int poppedValue = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

// Function to peek at the top element of the stack without popping
int peek(struct Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; // Return an error value
    }
    return stack.top->data;
}

// Function to display the elements of the stack
void display(struct Stack stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* current = stack.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    display(stack);

    int poppedValue = pop(&stack);
    if (poppedValue != -1) {
        printf("Popped item from the stack: %d\n", poppedValue);
    }

    display(stack);

    int topValue = peek(stack);
    if (topValue != -1) {
        printf("Top item of the stack: %d\n", topValue);
    }

    return 0;
}
