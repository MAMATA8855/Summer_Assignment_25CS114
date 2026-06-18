#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int i = 0, j = 0;
    
    printf("Union of arrays: ");
    
    while (i < n1 && j < n2) {
        while (i > 0 && i < n1 && arr1[i] == arr1[i - 1]) {
            i++;
        }
        while (j > 0 && j < n2 && arr2[j] == arr2[j - 1]) {
            j++;
        }
        
        if (i >= n1 || j >= n2) {
            break;
        }
        
        if (arr1[i] < arr2[j]) {
            printf("%d ", arr1[i]);
            i++;
        } else if (arr2[j] < arr1[i]) {
            printf("%d ", arr2[j]);
            j++;
        } else {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }
    
    while (i < n1) {
        if (i == 0 || arr1[i] != arr1[i - 1]) {
            printf("%d ", arr1[i]);
        }
        i++;
    }
    
    while (j < n2) {
        if (j == 0 || arr2[j] != arr2[j - 1]) {
            printf("%d ", arr2[j]);
        }
        j++;
    }
    
    printf("\n");
    return 0;
}