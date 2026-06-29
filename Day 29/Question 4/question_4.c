#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

void addProduct(FILE *file) {
    struct Product p;
    
    printf("Enter Product ID: ");
    scanf("%d", &p.id);
    getchar();
    
    printf("Enter Product Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = 0;
    
    printf("Enter Quantity: ");
    scanf("%d", &p.quantity);
    
    printf("Enter Price: ");
    scanf("%f", &p.price);
    
    fseek(file, 0, SEEK_END);
    fwrite(&p, sizeof(struct Product), 1, file);
    printf("Product added to stock successfully!\n");
}

void displayInventory(FILE *file) {
    struct Product p;
    rewind(file);
    
    printf("\n--- Current Inventory Status ---\n");
    printf("%-12s %-30s %-10s %-10s\n", "Product ID", "Product Name", "Quantity", "Price");
    printf("------------------------------------------------------------------\n");
    
    while (fread(&p, sizeof(struct Product), 1, file) == 1) {
        printf("%-12d %-30s %-10d $%-10.2f\n", p.id, p.name, p.quantity, p.price);
    }
}

void searchProduct(FILE *file) {
    struct Product p;
    int searchId;
    int found = 0;
    
    printf("Enter Product ID to search: ");
    scanf("%d", &searchId);
    
    rewind(file);
    while (fread(&p, sizeof(struct Product), 1, file) == 1) {
        if (p.id == searchId) {
            printf("\nProduct Found:\n");
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("Stock Quantity: %d\n", p.quantity);
            printf("Price per Unit: $%.2f\n", p.price);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Product with ID %d is not available in stock.\n", searchId);
    }
}

void updateStock(FILE *file) {
    struct Product p;
    int targetId;
    int newQuantity;
    int found = 0;
    long pos;
    
    printf("Enter Product ID to update inventory: ");
    scanf("%d", &targetId);
    
    rewind(file);
    while (fread(&p, sizeof(struct Product), 1, file) == 1) {
        if (p.id == targetId) {
            found = 1;
            pos = ftell(file) - sizeof(struct Product);
            
            printf("Current Quantity: %d\n", p.quantity);
            printf("Enter new total stock count: ");
            scanf("%d", &newQuantity);
            
            if (newQuantity >= 0) {
                p.quantity = newQuantity;
                fseek(file, pos, SEEK_SET);
                fwrite(&p, sizeof(struct Product), 1, file);
                printf("Inventory quantity updated successfully!\n");
            } else {
                printf("Invalid stock quantity entry.\n");
            }
            break;
        }
    }
    
    if (!found) {
        printf("Product code %d not matched in the records.\n", targetId);
    }
}

void deleteProduct(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error expanding product database file.\n");
        return;
    }
    
    FILE *tempFile = fopen("temp_inv.dat", "wb");
    if (!tempFile) {
        printf("Error allocating system temp block.\n");
        fclose(file);
        return;
    }
    
    struct Product p;
    int deleteId;
    int found = 0;
    
    printf("Enter Product ID to discard from inventory: ");
    scanf("%d", &deleteId);
    
    while (fread(&p, sizeof(struct Product), 1, file) == 1) {
        if (p.id == deleteId) {
            found = 1;
        } else {
            fwrite(&p, sizeof(struct Product), 1, tempFile);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(filename);
    rename("temp_inv.dat", filename);
    
    if (found) {
        printf("Product configuration record discarded cleanly.\n");
    } else {
        printf("Product index tracking not found.\n");
    }
}

int main() {
    const char *filename = "inventory.dat";
    FILE *file = fopen(filename, "rb+");
    
    if (!file) {
        file = fopen(filename, "wb+");
        if (!file) {
            printf("Inventory asset database failed to run.\n");
            return 1;
        }
    }
    
    int choice;
    while (1) {
        printf("\n=== Inventory Management System ===\n");
        printf("1. Add New Item\n");
        printf("2. Display Current Stock\n");
        printf("3. Search Stock Entry\n");
        printf("4. Update Stock Quantity\n");
        printf("5. Delete Outdated Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addProduct(file);
                break;
            case 2:
                displayInventory(file);
                break;
            case 3:
                searchProduct(file);
                break;
            case 4:
                updateStock(file);
                break;
            case 5:
                fclose(file);
                deleteProduct(filename);
                file = fopen(filename, "rb+");
                break;
            case 6:
                fclose(file);
                printf("Halting operations. Systems shutdown safely.\n");
                return 0;
            default:
                printf("Selection mismatch. Input valid execution parameter.\n");
        }
    }
    return 0;
}
