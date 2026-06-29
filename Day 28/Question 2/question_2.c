#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accountNo;
    char name[50];
    float balance;
};

void createAccount(FILE *file) {
    struct Account a;
    
    printf("Enter Account Number: ");
    scanf("%d", &a.accountNo);
    getchar();
    
    printf("Enter Account Holder Name: ");
    fgets(a.name, sizeof(a.name), stdin);
    a.name[strcspn(a.name, "\n")] = 0;
    
    printf("Enter Initial Deposit Amount: ");
    scanf("%f", &a.balance);
    
    fseek(file, 0, SEEK_END);
    fwrite(&a, sizeof(struct Account), 1, file);
    printf("Account created successfully!\n");
}

void displayDetails(FILE *file) {
    struct Account a;
    int searchNo;
    int found = 0;
    
    printf("Enter Account Number: ");
    scanf("%d", &searchNo);
    
    rewind(file);
    while (fread(&a, sizeof(struct Account), 1, file) == 1) {
        if (a.accountNo == searchNo) {
            printf("\n========================================\n");
            printf("            ACCOUNT DETAILS             \n");
            printf("========================================\n");
            printf("Account Number: %d\n", a.accountNo);
            printf("Account Holder: %s\n", a.name);
            printf("Current Balance: $%.2f\n", a.balance);
            printf("========================================\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Account number %d not found.\n", searchNo);
    }
}

void depositMoney(FILE *file) {
    struct Account a;
    int targetNo;
    float amount;
    int found = 0;
    long pos;
    
    printf("Enter Account Number: ");
    scanf("%d", &targetNo);
    
    rewind(file);
    while (fread(&a, sizeof(struct Account), 1, file) == 1) {
        if (a.accountNo == targetNo) {
            found = 1;
            pos = ftell(file) - sizeof(struct Account);
            
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            
            if (amount > 0) {
                a.balance += amount;
                fseek(file, pos, SEEK_SET);
                fwrite(&a, sizeof(struct Account), 1, file);
                printf("Deposit successful! New Balance: $%.2f\n", a.balance);
            } else {
                printf("Invalid deposit amount.\n");
            }
            break;
        }
    }
    
    if (!found) {
        printf("Account number %d not found.\n", targetNo);
    }
}

void withdrawMoney(FILE *file) {
    struct Account a;
    int targetNo;
    float amount;
    int found = 0;
    long pos;
    
    printf("Enter Account Number: ");
    scanf("%d", &targetNo);
    
    rewind(file);
    while (fread(&a, sizeof(struct Account), 1, file) == 1) {
        if (a.accountNo == targetNo) {
            found = 1;
            pos = ftell(file) - sizeof(struct Account);
            
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            
            if (amount > 0 && amount <= a.balance) {
                a.balance -= amount;
                fseek(file, pos, SEEK_SET);
                fwrite(&a, sizeof(struct Account), 1, file);
                printf("Withdrawal successful! New Balance: $%.2f\n", a.balance);
            } else if (amount > a.balance) {
                printf("Insufficient balance to complete transaction.\n");
            } else {
                printf("Invalid withdrawal amount.\n");
            }
            break;
        }
    }
    
    if (!found) {
        printf("Account number %d not found.\n", targetNo);
    }
}

void closeAccount(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening database file.\n");
        return;
    }
    
    FILE *tempFile = fopen("temp_bank.dat", "wb");
    if (!tempFile) {
        printf("Error creating temporary system storage.\n");
        fclose(file);
        return;
    }
    
    struct Account a;
    int deleteNo;
    int found = 0;
    
    printf("Enter Account Number to close: ");
    scanf("%d", &deleteNo);
    
    while (fread(&a, sizeof(struct Account), 1, file) == 1) {
        if (a.accountNo == deleteNo) {
            found = 1;
        } else {
            fwrite(&a, sizeof(struct Account), 1, tempFile);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(filename);
    rename("temp_bank.dat", filename);
    
    if (found) {
        printf("Account closed and records updated successfully.\n");
    } else {
        printf("Account record not found.\n");
    }
}

int main() {
    const char *filename = "banking.dat";
    FILE *file = fopen(filename, "rb+");
    
    if (!file) {
        file = fopen(filename, "wb+");
        if (!file) {
            printf("Banking database system failure.\n");
            return 1;
        }
    }
    
    int choice;
    while (1) {
        printf("\n=== Bank Account Management System ===\n");
        printf("1. Create New Account\n");
        printf("2. Check Balance & Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Close Account\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAccount(file);
                break;
            case 2:
                displayDetails(file);
                break;
            case 3:
                depositMoney(file);
                break;
            case 4:
                withdrawMoney(file);
                break;
            case 5:
                fclose(file);
                closeAccount(filename);
                file = fopen(filename, "rb+");
                break;
            case 6:
                fclose(file);
                printf("Ending bank session. Securely logged out.\n");
                return 0;
            default:
                printf("Selected option is invalid. Choose again.\n");
        }
    }
    return 0;
}
