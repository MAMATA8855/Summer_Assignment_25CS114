#include <stdio.h>

int main() {
    int num;
    int count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num == 0) {
        count = 1;
    } else {
        if (num < 0) {
            num = -num;
        }
        while (num > 0) {
            num = num / 10;
            count++;
        }
    }

    printf("Total digits: %d\n", count);

    return 0;
}
