#include <stdio.h>

int main() {
    int pin = 1234;
    int entered_pin;
    int choice;
    int attempts = 0;
    float balance = 5000.0;
    float amount;

    printf("Welcome to the ATM System\n");

    while (attempts < 3) {
        printf("Enter your 4-digit PIN: ");
        if (scanf("%d", &entered_pin) != 1) {
            printf("Invalid input.\n\n");
            while (getchar() != '\n');
            attempts++;
            continue;
        }

        if (entered_pin == pin) {
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("Card blocked due to too many incorrect attempts.\n");
        return 0;
    }

    while (1) {
        printf("\n--- ATM Main Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Selection must be a number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 4) {
            printf("Thank you for using our ATM. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Your current balance is: $%.2f\n", balance);
                break;

            case 2:
                printf("Enter deposit amount: $");
                if (scanf("%f", &amount) != 1 || amount <= 0) {
                    printf("Invalid deposit amount.\n");
                    while (getchar() != '\n');
                } else {
                    balance += amount;
                    printf("$%.2f successfully deposited.\n", amount);
                }
                break;

            case 3:
                printf("Enter withdrawal amount: $");
                if (scanf("%f", &amount) != 1 || amount <= 0) {
                    printf("Invalid withdrawal amount.\n");
                    while (getchar() != '\n');
                } else if (amount > balance) {
                    printf("Insufficient funds. Your balance is $%.2f\n", balance);
                } else {
                    balance -= amount;
                    printf("$%.2f successfully withdrawn.\n", amount);
                }
                break;

            default:
                printf("Invalid selection. Please choose an option from 1 to 4.\n");
        }
    }

    return 0;
}
