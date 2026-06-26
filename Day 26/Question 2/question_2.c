#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    if (age < 0) {
        printf("Age cannot be negative.\n");
    } else if (age >= 18) {
        printf("You are eligible to vote!\n");
    } else {
        int years_left = 18 - age;
        printf("You are not eligible to vote yet.\n");
        printf("You can vote in %d year(s).\n", years_left);
    }

    return 0;
}
