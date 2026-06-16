#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateLeft(int arr[], int size, int d) {
    d = d % size;
    if (d == 0) return;

    reverse(arr, 0, d - 1);
    reverse(arr, d, size - 1);
    reverse(arr, 0, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    rotateLeft(arr, size, d);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
