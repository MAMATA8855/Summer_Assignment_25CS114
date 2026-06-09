#include <stdio.h>

int main() {
    int n;          
    int sum = 0; 
    
    printf("Enter a positive number: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }
    printf("The sum of the first %d numbers is: %d\n", n, sum);

    return 0;
}
