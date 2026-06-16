#include <stdio.h>

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int removeDuplicates(int arr[], int size) {
    if (size == 0 || size == 1) return size;

    sortArray(arr, size);

    int uniqueIndex = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[uniqueIndex]) {
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }

    return uniqueIndex + 1;
}

int main() {
    int arr[] = {2, 3, 2, 1, 3, 4, 1};
    int size = sizeof(arr) / sizeof(arr);

    int newSize = removeDuplicates(arr, size);

    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
