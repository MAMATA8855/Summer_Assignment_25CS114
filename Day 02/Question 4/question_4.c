#include <stdio.h>

int main() {
    int num, original, remainder;
    int reversed = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    original = num;

    while (num > 0) {
        remainder = num % 10;
        reversed = (reversed * 10) + remainder;
        num = num / 10;
    }

    if (original == reversed) {
        printf(" It is a palindrome.\n");
    } else {
        printf(" It is not a palindrome.\n");
    }

    return 0;
}
