#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SalaryRecord {
    int empId;
    char name[50];
    float baseSalary;
    float allowance;
    float taxDeduction;
    float netSalary;
};

void addSalaryRecord(FILE *file) {
    struct SalaryRecord r;
    
    printf("Enter Employee ID: ");
    scanf("%d", &r.empId);
    getchar();
    
    printf("Enter Employee Name: ");
    fgets(r.name, sizeof(r.name), stdin);
    r.name[strcspn(r.name, "\n")] = 0;
    
    printf("Enter Base Salary: ");
    scanf("%f", &r.baseSalary);
    
    printf("Enter Allowances: ");
    scanf("%f", &r.allowance);
    
    printf("Enter Tax Deductions: ");
    scanf("%f", &r.taxDeduction);
    
    r.netSalary = r.baseSalary + r.allowance - r.taxDeduction;
    
    fseek(file, 0, SEEK_END);
    fwrite(&r, sizeof(struct SalaryRecord), 1, file);
    printf("Salary record processed and added successfully!\n");
}

void displaySalarySlip(FILE *file) {
    struct SalaryRecord r;
    int searchId;
    int found = 0;
    
    printf("Enter Employee ID to generate slip: ");
    scanf("%d", &searchId);
    
    rewind(file);
    while (fread(&r, sizeof(struct SalaryRecord), 1, file) == 1) {
        if (r.empId == searchId) {
            printf("\n========================================\n");
            printf("             SALARY SLIP                \n");
            printf("========================================\n");
            printf("Employee ID   : %d\n", r.empId);
            printf("Name          : %s\n", r.name);
            printf("----------------------------------------\n");
            printf("Base Salary   : $%.2f\n", r.baseSalary);
            printf("Allowances    : $%.2f\n", r.allowance);
            printf("Deductions    : $%.2f\n", r.taxDeduction);
            printf("----------------------------------------\n");
            printf("NET PAYABLE   : $%.2f\n", r.netSalary);
            printf("========================================\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Salary record for Employee ID %d not found.\n", searchId);
    }
}

void displayAllSalaries(FILE *file) {
    struct SalaryRecord r;
    rewind(file);
    
    printf("\n--- Payroll Summary ---\n");
    printf("%-10s %-25s %-12s %-12s %-12s\n", "ID", "Name", "Base", "Deductions", "Net Salary");
    printf("----------------------------------------------------------------─────────\n");
    
    while (fread(&r, sizeof(struct SalaryRecord), 1, file) == 1) {
        printf("%-10d %-25s %-12.2f %-12.2f %-12.2f\n", r.empId, r.name, r.baseSalary, r.taxDeduction, r.netSalary);
    }
}

void deleteSalaryRecord(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    
    FILE *tempFile = fopen("temp_sal.dat", "wb");
    if (!tempFile) {
        printf("Error creating temporary storage.\n");
        fclose(file);
        return;
    }
    
    struct SalaryRecord r;
    int deleteId;
    int found = 0;
    
    printf("Enter Employee ID to remove payroll record: ");
    scanf("%d", &deleteId);
    
    while (fread(&r, sizeof(struct SalaryRecord), 1, file) == 1) {
        if (r.empId == deleteId) {
            found = 1;
        } else {
            fwrite(&r, sizeof(struct SalaryRecord), 1, tempFile);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(filename);
    rename("temp_sal.dat", filename);
    
    if (found) {
        printf("Payroll record removed successfully.\n");
    } else {
        printf("Record not found.\n");
    }
}

int main() {
    const char *filename = "payroll.dat";
    FILE *file = fopen(filename, "rb+");
    
    if (!file) {
        file = fopen(filename, "wb+");
        if (!file) {
            printf("Payroll system initialization failed.\n");
            return 1;
        }
    }
    
    int choice;
    while (1) {
        printf("\n=== Salary Management System ===\n");
        printf("1. Add Salary Record\n");
        printf("2. Generate Employee Salary Slip\n");
        printf("3. View Payroll Summary\n");
        printf("4. Delete Salary Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addSalaryRecord(file);
                break;
            case 2:
                displaySalarySlip(file);
                break;
            case 3:
                displayAllSalaries(file);
                break;
            case 4:
                fclose(file);
                deleteSalaryRecord(filename);
                file = fopen(filename, "rb+");
                break;
            case 5:
                fclose(file);
                printf("Exiting management system.\n");
                return 0;
            default:
                printf("Invalid option selected. Try again.\n");
        }
    }
    return 0;
}
