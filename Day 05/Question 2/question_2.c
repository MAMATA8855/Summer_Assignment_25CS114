#include <stdio.h>

int main() {
    int original_num, temp, remainder;
    int total_sum = 0;

    printf("Enter an integer: ");
    scanf("%d", &original_num);

    temp = original_num;
    while (temp != 0) {
        remainder = temp % 10;

        int factorial = 1;
        for (int i = 1; i <= remainder; i++) {
            factorial *= i;
        }

        total_sum += factorial;
        temp /= 10;
    }

    if (total_sum == original_num && original_num > 0) {
        printf("%d is a strong number.\n", original_num);
    } else {
        printf("%d is not a strong number.\n", original_num);
    }

    return 0;
}

