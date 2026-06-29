#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Marksheet {
    int rollNo;
    char name[50];
    int math;
    int science;
    int english;
    int history;
    int total;
    float percentage;
    char grade[5];
};

void calculateGrade(struct Marksheet *m) {
    m->total = m->math + m->science + m->english + m->history;
    m->percentage = m->total / 4.0;
    
    if (m->math < 40 || m->science < 40 || m->english < 40 || m->history < 40) {
        strcpy(m->grade, "Fail");
    } else if (m->percentage >= 85) {
        strcpy(m->grade, "A+");
    } else if (m->percentage >= 70) {
        strcpy(m->grade, "A");
    } else if (m->percentage >= 55) {
        strcpy(m->grade, "B");
    } else if (m->percentage >= 40) {
        strcpy(m->grade, "C");
    } else {
        strcpy(m->grade, "Fail");
    }
}

void addMarksheet(FILE *file) {
    struct Marksheet m;
    
    printf("Enter Roll Number: ");
    scanf("%d", &m.rollNo);
    getchar();
    
    printf("Enter Student Name: ");
    fgets(m.name, sizeof(m.name), stdin);
    m.name[strcspn(m.name, "\n")] = 0;
    
    printf("Enter Math Marks (out of 100): ");
    scanf("%d", &m.math);
    
    printf("Enter Science Marks (out of 100): ");
    scanf("%d", &m.science);
    
    printf("Enter English Marks (out of 100): ");
    scanf("%d", &m.english);
    
    printf("Enter History Marks (out of 100): ");
    scanf("%d", &m.history);
    
    calculateGrade(&m);
    
    fseek(file, 0, SEEK_END);
    fwrite(&m, sizeof(struct Marksheet), 1, file);
    printf("Marksheet data saved successfully!\n");
}

void generateReportCard(FILE *file) {
    struct Marksheet m;
    int searchRoll;
    int found = 0;
    
    printf("Enter Roll Number to generate marksheet: ");
    scanf("%d", &searchRoll);
    
    rewind(file);
    while (fread(&m, sizeof(struct Marksheet), 1, file) == 1) {
        if (m.rollNo == searchRoll) {
            printf("\n========================================\n");
            printf("         OFFICIAL REPORT CARD           \n");
            printf("========================================\n");
            printf("Roll Number : %d\n", m.rollNo);
            printf("Student Name: %s\n", m.name);
            printf("----------------------------------------\n");
            printf("Subject     | Max Marks | Marks Obtained\n");
            printf("----------------------------------------\n");
            printf("Mathematics |    100    |      %d\n", m.math);
            printf("Science     |    100    |      %d\n", m.science);
            printf("English     |    100    |      %d\n", m.english);
            printf("History     |    100    |      %d\n", m.history);
            printf("----------------------------------------\n");
            printf("Total Marks : %d / 400\n", m.total);
            printf("Percentage  : %.2f%%\n", m.percentage);
            printf("Final Grade : %s\n", m.grade);
            printf("========================================\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No records found for Roll Number %d.\n", searchRoll);
    }
}

void displaySummaryTable(FILE *file) {
    struct Marksheet m;
    rewind(file);
    
    printf("\n--- Class Performance Summary ---\n");
    printf("%-10s %-25s %-8s %-12s %-6s\n", "Roll No", "Name", "Total", "Percentage", "Grade");
    printf("-----------------------------------------------------------------\n");
    
    while (fread(&m, sizeof(struct Marksheet), 1, file) == 1) {
        printf("%-10d %-25s %-8d %-11.2f%% %-6s\n", m.rollNo, m.name, m.total, m.percentage, m.grade);
    }
}

void removeMarksheet(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening database file.\n");
        return;
    }
    
    FILE *tempFile = fopen("temp_marks.dat", "wb");
    if (!tempFile) {
        printf("Error creating temporary system storage.\n");
        fclose(file);
        return;
    }
    
    struct Marksheet m;
    int deleteRoll;
    int found = 0;
    
    printf("Enter Roll Number to delete record: ");
    scanf("%d", &deleteRoll);
    
    while (fread(&m, sizeof(struct Marksheet), 1, file) == 1) {
        if (m.rollNo == deleteRoll) {
            found = 1;
        } else {
            fwrite(&m, sizeof(struct Marksheet), 1, tempFile);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(filename);
    rename("temp_marks.dat", filename);
    
    if (found) {
        printf("Marksheet deleted successfully.\n");
    } else {
        printf("Record code not found.\n");
    }
}

int main() {
    const char *filename = "marksheets.dat";
    FILE *file = fopen(filename, "rb+");
    
    if (!file) {
        file = fopen(filename, "wb+");
        if (!file) {
            printf("Marksheet management system failed to start.\n");
            return 1;
        }
    }
    
    int choice;
    while (1) {
        printf("\n=== Marksheet Generation System ===\n");
        printf("1. Add Student Marks\n");
        printf("2. Generate Student Report Card\n");
        printf("3. View All Summaries\n");
        printf("4. Delete Marksheet Entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMarksheet(file);
                break;
            case 2:
                generateReportCard(file);
                break;
            case 3:
                displaySummaryTable(file);
                break;
            case 4:
                fclose(file);
                removeMarksheet(filename);
                file = fopen(filename, "rb+");
                break;
            case 5:
                fclose(file);
                printf("Closing system software.\n");
                return 0;
            default:
                printf("Option not recognized. Please choose again.\n");
        }
    }
    return 0;
}
