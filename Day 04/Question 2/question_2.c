#include <stdio.h>

int main() {
    int n;
    long long first = 0, second = 1, next;

    printf("Enter the position (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Please enter a position greater than 0.\n");
        return 1;
    }

    if (n == 1) {
        printf("The 1st Fibonacci term is: 0\n");
        return 0;
    }

    for (int i = 3; i <= n; i++) {
        next = first + second;
        first = second;
        second = next;
    }

    printf("The %dth Fibonacci term is: %lld\n", n, second);
    return 0;
}
