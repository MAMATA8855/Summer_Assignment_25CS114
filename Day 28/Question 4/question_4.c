#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    int id;
    char name[50];
    char phone[20];
    char email[50];
};

void addContact(FILE *file) {
    struct Contact c;
    
    printf("Enter Contact ID: ");
    scanf("%d", &c.id);
    getchar();
    
    printf("Enter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = 0;
    
    printf("Enter Phone Number: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;
    
    printf("Enter Email Address: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = 0;
    
    fseek(file, 0, SEEK_END);
    fwrite(&c, sizeof(struct Contact), 1, file);
    printf("Contact added successfully!\n");
}

void displayContacts(FILE *file) {
    struct Contact c;
    rewind(file);
    
    printf("\n--- Contact List ---\n");
    printf("%-10s %-25s %-20s %-30s\n", "ID", "Name", "Phone", "Email");
    printf("--------------------------------------------------------------------------------\n");
    
    while (fread(&c, sizeof(struct Contact), 1, file) == 1) {
        printf("%-10d %-25s %-20s %-30s\n", c.id, c.name, c.phone, c.email);
    }
}

void searchContact(FILE *file) {
    struct Contact c;
    char searchName[50];
    int found = 0;
    
    getchar();
    printf("Enter Name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    
    rewind(file);
    while (fread(&c, sizeof(struct Contact), 1, file) == 1) {
        if (strcasecmp(c.name, searchName) == 0) {
            printf("\nContact Found:\n");
            printf("ID: %d\n", c.id);
            printf("Name: %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            printf("Email: %s\n", c.email);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No contact found matching the name \"%s\".\n", searchName);
    }
}

void deleteContact(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening directory database.\n");
        return;
    }
    
    FILE *tempFile = fopen("temp_contact.dat", "wb");
    if (!tempFile) {
        printf("Error creating temporary system storage.\n");
        fclose(file);
        return;
    }
    
    struct Contact c;
    int deleteId;
    int found = 0;
    
    printf("Enter Contact ID to delete: ");
    scanf("%d", &deleteId);
    
    while (fread(&c, sizeof(struct Contact), 1, file) == 1) {
        if (c.id == deleteId) {
            found = 1;
        } else {
            fwrite(&c, sizeof(struct Contact), 1, tempFile);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(filename);
    rename("temp_contact.dat", filename);
    
    if (found) {
        printf("Contact deleted successfully.\n");
    } else {
        printf("Contact entry not found.\n");
    }
}

int main() {
    const char *filename = "contacts.dat";
    FILE *file = fopen(filename, "rb+");
    
    if (!file) {
        file = fopen(filename, "wb+");
        if (!file) {
            printf("Contact database setup failed.\n");
            return 1;
        }
    }
    
    int choice;
    while (1) {
        printf("\n=== Contact Management System ===\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Delete Contact Entry\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addContact(file);
                break;
            case 2:
                displayContacts(file);
                break;
            case 3:
                searchContact(file);
                break;
            case 4:
                fclose(file);
                deleteContact(filename);
                file = fopen(filename, "rb+");
                break;
            case 5:
                fclose(file);
                printf("Closing contact directory application.\n");
                return 0;
            default:
                printf("Invalid selection option. Try again.\n");
        }
    }
    return 0;
}
