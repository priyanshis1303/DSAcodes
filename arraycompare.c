#include<stdio.h>

// Function to compare two arrays and return 1 if they are identical, 0 otherwise
int areArraysIdentical(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // Arrays are not identical
        }
    }
    return 1; // Arrays are identical
}

int main() {
    int size;
    
    printf("Enter the size of the arrays: ");
    scanf("%d", &size);
    
    int arr1[size];
    int arr2[size];
    
    printf("Enter elements for the first array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements for the second array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    int result = areArraysIdentical(arr1, arr2, size);

    if (result) {
        printf("The arrays are identical.\n");
    } else {
        printf("The arrays are not identical.\n");
    }

    return 0;
}

