#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

void addEmployee(FILE *file) {
    struct Employee e;
    
    printf("Enter Employee ID: ");
    scanf("%d", &e.id);
    getchar();
    
    printf("Enter Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = 0;
    
    printf("Enter Department: ");
    fgets(e.department, sizeof(e.department), stdin);
    e.department[strcspn(e.department, "\n")] = 0;
    
    printf("Enter Salary: ");
    scanf("%f", &e.salary);
    
    fseek(file, 0, SEEK_END);
    fwrite(&e, sizeof(struct Employee), 1, file);
    printf("Employee record added successfully!\n");
}

void displayEmployees(FILE *file) {
    struct Employee e;
    rewind(file);
    
    printf("\n--- Employee Records ---\n");
    printf("%-10s %-25s %-20s %-10s\n", "ID", "Name", "Department", "Salary");
    printf("------------------------------------------------------------------\n");
    
    while (fread(&e, sizeof(struct Employee), 1, file) == 1) {
        printf("%-10d %-25s %-20s %-10.2f\n", e.id, e.name, e.department, e.salary);
    }
}

void searchEmployee(FILE *file) {
    struct Employee e;
    int searchId;
    int found = 0;
    
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);
    
    rewind(file);
    while (fread(&e, sizeof(struct Employee), 1, file) == 1) {
        if (e.id == searchId) {
            printf("\nRecord Found:\n");
            printf("ID: %d\n", e.id);
            printf("Name: %s\n", e.name);
            printf("Department: %s\n", e.department);
            printf("Salary: %.2f\n", e.salary);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
}

void deleteEmployee(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }
    
    FILE *tempFile = fopen("temp_emp.dat", "wb");
    if (!tempFile) {
        printf("Error creating temporary file.\n");
        fclose(file);
        return;
    }
    
    struct Employee e;
    int deleteId;
    int found = 0;
    
    printf("Enter Employee ID to delete: ");
    scanf("%d", &deleteId);
    
    while (fread(&e, sizeof(struct Employee), 1, file) == 1) {
        if (e.id == deleteId) {
            found = 1;
        } else {
            fwrite(&e, sizeof(struct Employee), 1, tempFile);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(filename);
    rename("temp_emp.dat", filename);
    
    if (found) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Record not found.\n");
    }
}

int main() {
    const char *filename = "employees.dat";
    FILE *file = fopen(filename, "rb+");
    
    if (!file) {
        file = fopen(filename, "wb+");
        if (!file) {
            printf("File initialization failed.\n");
            return 1;
        }
    }
    
    int choice;
    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                displayEmployees(file);
                break;
            case 3:
                searchEmployee(file);
                break;
            case 4:
                fclose(file);
                deleteEmployee(filename);
                file = fopen(filename, "rb+");
                break;
            case 5:
                fclose(file);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
