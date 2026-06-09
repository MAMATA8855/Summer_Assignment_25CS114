#include <stdio.h>

int main() {
    int decimal, temp;
    int binary[32];
    int index = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    if (decimal == 0) {
        printf("Binary equivalent: 0\n");
        return 0;
    }

    temp = decimal;
    if (temp < 0) {
        temp = -temp;
    }

    while (temp > 0) {
        binary[index] = temp % 2;
        temp /= 2;
        index++;
    }

    printf("Binary equivalent: ");
    if (decimal < 0) {
        printf("-");
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}
