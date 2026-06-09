#include <stdio.h>

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int position;

    printf("Enter the position: ");
    scanf("%d", &position);

    if (position < 0) {
        printf("Please enter a non-negative position.\n");
        return 1;
    }

    printf("Fibonacci number at position %d is %d\n", position, fibonacci(position));

    return 0;
}
