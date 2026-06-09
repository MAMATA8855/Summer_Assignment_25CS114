#include <stdio.h>

int main() {
    long long binary, temp;
    int decimal = 0;
    int base = 1;
    int remainder;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    temp = binary;
    while (temp != 0) {
        remainder = temp % 10;
        decimal += remainder * base;
        base *= 2;
        temp /= 10;
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}
