#include <stdio.h>

int main() {
    int terms;
    int first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    if (terms <= 0) {
        printf("Please enter a positive number greater than 0.\n");
        return 1;
    }

    printf("Fibonacci Series: ");

    for (int i = 1; i <= terms; i++) {
        printf("%d ", first);
        next = first + second;
        first = second;
        second = next;
    }

    printf("\n");
    return 0;
}

