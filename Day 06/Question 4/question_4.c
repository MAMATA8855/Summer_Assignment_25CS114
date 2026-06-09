#include <stdio.h>

int main() {
    double base;
    int exponent;
    double result = 1.0;

    printf("Enter base: ");
    scanf("%lf", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);

    int abs_exponent = exponent;
    if (exponent < 0) {
        abs_exponent = -exponent;
    }

    for (int i = 0; i < abs_exponent; i++) {
        result *= base;
    }

    if (exponent < 0) {
        if (result != 0) {
            result = 1.0 / result;
        } else {
            printf("Error: Division by zero.\n");
            return 1;
        }
    }

    printf("Result: %.6lf\n", result);

    return 0;
}
