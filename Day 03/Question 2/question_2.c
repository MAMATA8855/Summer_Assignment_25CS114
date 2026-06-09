#include <stdio.h>

int main() {
    int start, end;

    printf("Enter lower limit: ");
    scanf("%d", &start);
    printf("Enter upper limit: ");
    scanf("%d", &end);

    printf("Prime numbers: ");

    for (int num = start; num <= end; num++) {
        if (num > 1) {
            int count = 0;

            for (int i = 1; i <= num; i++) {
                if (num % i == 0) {
                    count++;
                }
            }

            if (count == 2) {
                printf("%d ", num);
            }
        }
    }
    printf("\n");

    return 0;
}
