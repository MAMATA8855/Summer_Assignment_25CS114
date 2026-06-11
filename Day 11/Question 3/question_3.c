#include <stdio.h>

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    int check_num = 29;
    
    if (is_prime(check_num)) {
        printf("%d is a prime number.\n", check_num);
    } else {
        printf("%d is not a prime number.\n", check_num);
    }
    
    return 0;
}
