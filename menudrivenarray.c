#include <stdio.h>

// Function to insert an element into an array at a specified position
void insert(int arr[], int size, int element, int position) {
    if (size >= 100) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }

    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;
    printf("Element %d inserted at position %d.\n", element, position);
}

// Function to delete an element from an array at a specified position
int deleteElement(int arr[], int size, int position) {
    if (size == 0) {
        printf("Array is empty. Cannot delete elements.\n");
        return size;
    }

    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return size;
    }

    int deletedElement = arr[position];

    // Shift elements to the left to fill the gap
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    printf("Element %d deleted from position %d.\n", deletedElement, position);
    return size;
}

// Function to traverse and display the elements of the array
void traverse(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to search for an element in the array
int search(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[100];
    int size = 0;
    int choice, element, position, searchElement, result;

    while (1) {
        printf("\nMenu:\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. TRAVERSE\n");
        printf("4. SEARCH\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insert(arr, size, element, position);
                size++;
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                size = deleteElement(arr, size, position);
                break;

            case 3:
                traverse(arr, size);
                break;

            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &searchElement);
                result = search(arr, size, searchElement);
                if (result != -1) {
                    printf("Element %d found at position %d.\n", searchElement, result);
                } else {
                    printf("Element %d not found in the array.\n", searchElement);
                }
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
