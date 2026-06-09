#include <stdio.h>

int reverse_number(int n, int reversed) {
    if (n == 0) {
        return reversed;
    }
    return reverse_number(n / 10, reversed * 10 + (n % 10));
}

int main() {
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    int is_negative = 0;
    int temp = num;
    if (temp < 0) {
        is_negative = 1;
        temp = -temp;
    }

    int result = reverse_number(temp, 0);

    if (is_negative) {
        result = -result;
    }

    printf("Reversed number: %d\n", result);

    return 0;
}
