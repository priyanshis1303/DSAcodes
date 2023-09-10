#include<stdio.h>
#include<math.h>

// Function to check if a number is a perfect square
int isPerfectSquare(int n) {
    int sqrtN = sqrt(n);
    return sqrtN * sqrtN == n;
}

// Function to check if a number is a Fibonacci number
int isFibonacci(int n) {
    // A number is Fibonacci if and only if one of (5*n*n + 4) or (5*n*n - 4) is a perfect square
    return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isFibonacci(num)) {
        printf("%d is a Fibonacci number.\n", num);
    } else {
        printf("%d is not a Fibonacci number.\n", num);
    }

    return 0;
}
