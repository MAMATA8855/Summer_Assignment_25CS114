#include <stdio.h>

int find_factorial(int n) {
    int val = 1;
    
    for (int i = 1; i <= n; i++) {
        val = val * i;
    }
    
    return val;
}

int main() {
    int number = 5;
    int answer;

    answer = find_factorial(number);
    printf("Factorial of %d is %d\n", number, answer);

    return 0;
}
