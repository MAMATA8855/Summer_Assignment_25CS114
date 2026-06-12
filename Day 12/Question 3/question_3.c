#include <stdio.h>

void printFibonacci(int terms) {
    int t1 = 0;
    int t2 = 1;
    int nextTerm;

    if (terms <= 0) {
        printf("Please enter a positive integer.\n");
        return;
    }

    printf("Fibonacci Sequence: ");

    for (int i = 1; i <= terms; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

int main() {
    int count;

    printf("Enter the number of terms: ");
    scanf("%d", &count);

    printFibonacci(count);

    return 0;
}

