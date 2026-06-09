#include <stdio.h>

int main() {
    long long num;
    long long largest_prime = -1;

    printf("Enter a positive integer: ");
    scanf("%lld", &num);

    if (num <= 1) {
        printf("No prime factors exist for %lld.\n", num);
        return 0;
    }

    while (num % 2 == 0) {
        largest_prime = 2;
        num /= 2;
    }

    for (long long i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            largest_prime = i;
            num /= i;
        }
    }

    if (num > 2) {
        largest_prime = num;
    }

    printf("The largest prime factor is: %lld\n", largest_prime);

    return 0;
}
