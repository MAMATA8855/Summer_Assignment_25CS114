#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ticket {
    int bookingId;
    char passengerName[50];
    char movieTitle[50];
    int seatNo;
    float price;
};

void bookTicket(FILE *file) {
    struct Ticket t;
    
    printf("Enter Booking ID: ");
    scanf("%d", &t.bookingId);
    getchar();
    
    printf("Enter Passenger Name: ");
    fgets(t.passengerName, sizeof(t.passengerName), stdin);
    t.passengerName[strcspn(t.passengerName, "\n")] = 0;
    
    printf("Enter Movie/Show Title: ");
    fgets(t.movieTitle, sizeof(t.movieTitle), stdin);
    t.movieTitle[strcspn(t.movieTitle, "\n")] = 0;
    
    printf("Enter Seat Number: ");
    scanf("%d", &t.seatNo);
    
    printf("Enter Ticket Price: ");
    scanf("%f", &t.price);
    
    fseek(file, 0, SEEK_END);
    fwrite(&t, sizeof(struct Ticket), 1, file);
    printf("Ticket booked successfully!\n");
}

void viewTicket(FILE *file) {
    struct Ticket t;
    int searchId;
    int found = 0;
    
    printf("Enter Booking ID: ");
    scanf("%d", &searchId);
    
    rewind(file);
    while (fread(&t, sizeof(struct Ticket), 1, file) == 1) {
        if (t.bookingId == searchId) {
            printf("\n========================================\n");
            printf("             TICKET DETAILS             \n");
            printf("========================================\n");
            printf("Booking ID    : %d\n", t.bookingId);
            printf("Passenger     : %s\n", t.passengerName);
            printf("Show/Movie    : %s\n", t.movieTitle);
            printf("Seat Number   : %d\n", t.seatNo);
            printf("Total Paid    : $%.2f\n", t.price);
            printf("========================================\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No booking found with ID %d.\n", searchId);
    }
}

void displayAllBookings(FILE *file) {
    struct Ticket t;
    rewind(file);
    
    printf("\n--- Active Ticket Bookings ---\n");
    printf("%-10s %-20s %-20s %-8s %-10s\n", "ID", "Passenger", "Show", "Seat", "Price");
    printf("----------------------------------------------------------------------\n");
    
    while (fread(&t, sizeof(struct Ticket), 1, file) == 1) {
        printf("%-10d %-20s %-20s %-8d $%-10.2f\n", t.bookingId, t.passengerName, t.movieTitle, t.seatNo, t.price);
    }
}

void cancelTicket(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening ticketing database.\n");
        return;
    }
    
    FILE *tempFile = fopen("temp_ticket.dat", "wb");
    if (!tempFile) {
        printf("Error creating temporary system storage.\n");
        fclose(file);
        return;
    }
    
    struct Ticket t;
    int deleteId;
    int found = 0;
    
    printf("Enter Booking ID to cancel: ");
    scanf("%d", &deleteId);
    
    while (fread(&t, sizeof(struct Ticket), 1, file) == 1) {
        if (t.bookingId == deleteId) {
            found = 1;
        } else {
            fwrite(&t, sizeof(struct Ticket), 1, tempFile);
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    remove(filename);
    rename("temp_ticket.dat", filename);
    
    if (found) {
        printf("Ticket booking cancelled successfully.\n");
    } else {
        printf("Booking record not found.\n");
    }
}

int main() {
    const char *filename = "bookings.dat";
    FILE *file = fopen(filename, "rb+");
    
    if (!file) {
        file = fopen(filename, "wb+");
        if (!file) {
            printf("Ticketing system core initialization failed.\n");
            return 1;
        }
    }
    
    int choice;
    while (1) {
        printf("\n=== Ticket Booking System ===\n");
        printf("1. Book New Ticket\n");
        printf("2. View Ticket Details\n");
        printf("3. Display All Bookings\n");
        printf("4. Cancel Ticket Booking\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                bookTicket(file);
                break;
            case 2:
                viewTicket(file);
                break;
            case 3:
                displayAllBookings(file);
                break;
            case 4:
                fclose(file);
                cancelTicket(filename);
                file = fopen(filename, "rb+");
                break;
            case 5:
                fclose(file);
                printf("Closing system database. Thank you!\n");
                return 0;
            default:
                printf("Invalid selection. Please choose a valid index.\n");
        }
    }
    return 0;
}
