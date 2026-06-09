#include <stdio.h>
#include <math.h>

int main() {
    int start, end;

    printf("Enter lower bound: ");
    scanf("%d", &start);
    printf("Enter upper bound: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);

    for (int i = start; i <= end; i++) {
        int temp = i;
        int digits = 0;
        double result = 0.0;

        while (temp != 0) {
            temp /= 10;
            digits++;
        }

        temp = i;
        while (temp != 0) {
            int remainder = temp % 10;
            result += pow(remainder, digits);
            temp /= 10;
        }

        if ((int)result == i && i != 0) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
