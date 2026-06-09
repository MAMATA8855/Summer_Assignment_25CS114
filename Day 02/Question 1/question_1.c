#include <stdio.h>

int main() {
    int num;
    int sum = 0;
    int remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        num = -num;
    }

    while (num > 0) {
        remainder = num % 10;
        sum = sum + remainder;
        num = num / 10;
    }

    printf("Sum of digits: %d\n", sum);

    return 0;
}
