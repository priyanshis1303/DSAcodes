#include<stdio.h>

// Function to calculate and print Pascal's Triangle
void generatePascalsTriangle(int numRows) {
    int pascalTriangle[numRows][numRows];

    // Fill the triangle with zeros
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
            pascalTriangle[i][j] = 0;
        }
    }

    // Calculate and fill the triangle
    for (int i = 0; i < numRows; i++) {
        pascalTriangle[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
        }
    }

    // Print Pascal's Triangle
    printf("Pascal's Triangle for %d rows:\n", numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", pascalTriangle[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);

    generatePascalsTriangle(numRows);

    return 0;
}
