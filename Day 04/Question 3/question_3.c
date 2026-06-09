#include <stdio.h>

int main() {
    int original_num, temp, remainder;
    int digits = 0;
    int result = 0;

    printf("Enter an integer: ");
    scanf("%d", &original_num);

    temp = original_num;
    while (temp != 0) {
        temp /= 10;
        digits++;
    }

    temp = original_num;
    while (temp != 0) {
        remainder = temp % 10;
        
        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= remainder;
        }
        
        result += power;
        temp /= 10;
    }

    if (result == original_num) {
        printf("%d is an Armstrong number.\n", original_num);
    } else {
        printf("%d is not an Armstrong number.\n", original_num);
    }

    return 0;
}
