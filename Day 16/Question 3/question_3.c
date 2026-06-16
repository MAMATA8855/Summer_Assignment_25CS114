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

int findPairWithSum(int arr[], int size, int target, int *num1, int *num2) {
    sortArray(arr, size);

    int left = 0;
    int right = size - 1;

    while (left < right) {
        int currentSum = arr[left] + arr[right];

        if (currentSum == target) {
            *num1 = arr[left];
            *num2 = arr[right];
            return 1;
        } else if (currentSum < target) {
            left++;
        } else {
            right--;
        }
    }
    return 0;
}

int main() {
    int arr[] = {8, 7, 2, 5, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int num1 = 0, num2 = 0;

    if (findPairWithSum(arr, size, target, &num1, &num2)) {
        printf("%d %d\n", num1, num2);
    } else {
        printf("No pair found\n");
    }

    return 0;
}
