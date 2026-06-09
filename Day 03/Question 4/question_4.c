#include <stdio.h>

int main() {
    int n1, n2, max;

    printf("Enter two numbers: ");
    scanf("%d %d", &n1, &n2);

    max = n1;
    if (n2 > max) {
        max = n2;
    }

    while (1) {
        if (max % n1 == 0) {
            if (max % n2 == 0) {
                printf("LCM is: %d\n", max);
                break;
            }
        }
        max++;
    }

    return 0;
}
