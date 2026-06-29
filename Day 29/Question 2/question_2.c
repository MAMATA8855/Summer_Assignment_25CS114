#include <stdio.h>
#include <stdlib.h>

void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *size, int capacity) {
    if (*size >= capacity) {
        printf("Error: Array is full.\n");
        return;
    }
    
    int element, position;
    printf("Enter element to insert: ");
    scanf("%d", &element);
    printf("Enter position (0 to %d): ", *size);
    scanf("%d", &position);
    
    if (position < 0 || position > *size) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Error: Array is empty.\n");
        return;
    }
    
    int position;
    printf("Enter position to delete (0 to %d): ", *size - 1);
    scanf("%d", &position);
    
    if (position < 0 || position >= *size) {
        printf("Invalid position!\n");
        return;
    }
    
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--;
    printf("Element deleted successfully.\n");
}

void searchElement(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    
    int target, found = 0;
    printf("Enter element to search: ");
    scanf("%d", &target);
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at position index %d.\n", i);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Element %d not found in the array.\n", target);
    }
}

void sortArray(int arr[], int size) {
    if (size <= 1) {
        printf("Array is already sorted.\n");
        return;
    }
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted in ascending order.\n");
}

int main() {
    int capacity = 100;
    int arr[100];
    int size = 0;
    int choice;
    
    printf("Enter initial number of elements (max 100): ");
    scanf("%d", &size);
    if (size > capacity || size < 0) {
        size = 0;
    }
    
    if (size > 0) {
        printf("Enter %d elements:\n", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    }
    
    while (1) {
        printf("\n=== Menu-Driven Array Operations ===\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Sort Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                insertElement(arr, &size, capacity);
                break;
            case 3:
                deleteElement(arr, &size);
                break;
            case 4:
                searchElement(arr, size);
                break;
            case 5:
                sortArray(arr, size);
                break;
            case 6:
                printf("Exiting system utility. Goodbye!\n");
                return 0;
            default:
                printf("Invalid selection. Try picking an available menu number.\n");
        }
    }
    return 0;
}
