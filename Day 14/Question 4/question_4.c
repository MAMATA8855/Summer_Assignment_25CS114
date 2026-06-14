#include <stdio.h>

void findDuplicates(int arr[], int size) {
    int foundDuplicate = 0;
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                int alreadyPrinted = 0;
                for (int k = 0; k < i; k++) {
                    if (arr[k] == arr[i]) {
                        alreadyPrinted = 1;
                        break;
                    }
                }
                if (!alreadyPrinted) {
                    printf("%d ", arr[i]);
                    foundDuplicate = 1;
                }
                break;
            }
        }
    }
    
    if (!foundDuplicate) {
        printf("No duplicate elements found.");
    }
    printf("\n");
}

int main() {
    int numbers[] = {4, 3, 2, 7, 8, 2, 3, 1, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Duplicate elements: ");
    findDuplicates(numbers, size);

    return 0;
}
