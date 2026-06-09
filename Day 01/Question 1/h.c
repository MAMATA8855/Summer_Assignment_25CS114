#include <stdio.h>

int main() {
    int n;          // This will hold the user's number
    int sum = 0;    // This will hold the running total

    // 1. Ask the user for a number
    printf("Enter a positive number: ");
    scanf("%d", &n);

    // 2. Loop from 1 up to N, adding each number to the sum
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }

    // 3. Print the final answer
    printf("The sum of the first %d numbers is: %d\n", n, sum);

    return 0;
}
