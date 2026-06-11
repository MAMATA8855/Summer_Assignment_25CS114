#include <stdio.h>

int add_numbers(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int num1 = 12;
    int num2 = 25;
    int total;

    total = add_numbers(num1, num2);
    printf("The sum is: %d\n", total);

    return 0;
}
