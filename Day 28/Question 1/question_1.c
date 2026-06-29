#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[50];
    int copies;
};

void addBook(FILE *file) {
    struct Book b;
    
    printf("Enter Book ID: ");
    scanf("%d", &b.id);
    getchar();
    
    printf("Enter Book Title: ");
    fgets(b.title, sizeof(b.title), stdin);
    b.title[strcspn(b.title, "\n")] = 0;
    
    printf("Enter Author Name: ");
    fgets(b.author, sizeof(b.author), stdin);
    b.author[strcspn(b.author, "\n")] = 0;
    
    printf("Enter Number of Copies: ");
    scanf("%d", &b.copies);
    
    fseek(file, 0, SEEK_END);
    fwrite(&b, sizeof(struct Book), 1, file);
    printf("Book added to the library catalogue successfully!\n");
}

void displayBooks(FILE *file) {
    struct Book b;
    rewind(file);
    
    printf("\n--- Library Catalogue ---\n");
    printf("%-10s %-40s %-25s %-10s\n", "Book ID", "Title", "Author", "Copies");
    printf("------------------------------------------------------------------------------------\n");
    
    while (fread(&b, sizeof(struct Book), 1, file) == 1) {
        printf("%-10d %-40s %-25s %-10d\n", b.id, b.title, b.author, b.copies);
    }
}

void searchBook(FILE *file) {
    struct Book b;
    int choice;
    int found = 0;
    
    printf("Search by:\n1. Book ID\n2. Book Title\nEnter choice: ");
    scanf("%d", &choice);
    getchar();
    
    rewind(file);
    if (choice == 1) {
        int searchId;
        printf("Enter Book ID to search: ");
        scanf("%d", &searchId);
        
        while (fread(&b, sizeof(struct Book), 1, file) == 1) {
            if (b.id == searchId) {
                printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\nAvailable Copies: %d\n", b.id, b.title, b.author, b.copies);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        char searchTitle[100];
        printf("Enter Book Title to search: ");
        fgets(searchTitle, sizeof(searchTitle), stdin);
        searchTitle[strcspn(searchTitle, "\n")] = 0;
        
        while (fread(&b, sizeof(struct Book), 1, file) == 1) {
            if (strcasecmp(b.title, searchTitle) == 0) {
                printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\nAvailable Copies: %d\n", b.id, b.title, b.author, b.copies);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("Requested book could not be found in the system.\n");
    }
}

void issueReturnBook(FILE *file, int mode) {
    struct Book b;
    int targetId;
    int found = 0;
    long pos;
    
    printf("Enter Book ID: ");
    scanf("%d", &targetId);
    
    rewind(file);
    while (fread(&b, sizeof(struct Book), 1, file) == 1) {
        if (b.id == targetId) {
            found = 1;
            pos = ftell(file) - sizeof(struct Book);
            
            if (mode == 1) {
                if (b.copies > 0) {
                    b.copies--;
                    fseek(file, pos, SEEK_SET);
                    fwrite(&b, sizeof(struct Book), 1, file);
                    printf("Book issued successfully! Remaining copies: %d\n", b.copies);
                } else {
                    printf("Sorry, this book is currently out of stock.\n");
                }
            } else if (mode == 2) {
                b.copies++;
                fseek(file, pos, SEEK_SET);
                fwrite(&b, sizeof(struct Book), 1, file);
                printf("Book returned successfully! Total copies now: %d\n", b.copies);
            }
            break;
        }
    }
    
    if (!found) {
        printf("Book ID %d does not exist in the records.\n", targetId);
    }
}

void deleteBook(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening database file.\n");
        return;
    }
    
    FILE *tempFile = fopen("temp_lib.dat", "wb");
    if (!tempFile) {
        printf("Error creating temporary system storage.\n");
        fclose(file);
        return;
    }
    
    struct Book b;
    int deleteId;
    int found = 0;
    
    printf("Enter Book ID to permanently remove: ");
    scanf("%d", &deleteId);
    
    while (fread(&b, sizeof(struct Book), 1, file) == 1) {
        if (b.id == deleteId) {
            found = 1;
        } else {
            fwrite(&b, sizeof(struct Book), 1, tempFile);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(filename);
    rename("temp_lib.dat", filename);
    
    if (found) {
        printf("Book record completely removed from inventory.\n");
    } else {
        printf("Record match not found.\n");
    }
}

int main() {
    const char *filename = "library.dat";
    FILE *file = fopen(filename, "rb+");
    
    if (!file) {
        file = fopen(filename, "wb+");
        if (!file) {
            printf("Library database configuration failed.\n");
            return 1;
        }
    }
    
    int choice;
    while (1) {
        printf("\n=== Library Management System ===\n");
        printf("1. Add New Book\n");
        printf("2. View Inventory Catalogue\n");
        printf("3. Search for a Book\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Delete Book Record\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(file);
                break;
            case 2:
                displayBooks(file);
                break;
            case 3:
                searchBook(file);
                break;
            case 4:
                issueReturnBook(file, 1);
                break;
            case 5:
                issueReturnBook(file, 2);
                break;
            case 6:
                fclose(file);
                deleteBook(filename);
                file = fopen(filename, "rb+");
                break;
            case 7:
                fclose(file);
                printf("Terminating session. Goodbye!\n");
                return 0;
            default:
                printf("Option unrecognised. Try entering a correct item.\n");
        }
    }
    return 0;
}
