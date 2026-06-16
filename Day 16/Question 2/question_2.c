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

int findMaxFrequencyElement(int arr[], int size) {
    if (size == 0) return -1;

    sortArray(arr, size);

    int maxElement = arr[0];
    int maxCount = 1;
    int currentCount = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1]) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                maxElement = arr[i - 1];
            }
            currentCount = 1;
        }
    }

    if (currentCount > maxCount) {
        maxCount = currentCount;
        maxElement = arr[size - 1];
    }

    return maxElement;
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 1, 3, 3, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxFreqElement = findMaxFrequencyElement(arr, size);
    printf("%d\n", maxFreqElement);

    return 0;
}
