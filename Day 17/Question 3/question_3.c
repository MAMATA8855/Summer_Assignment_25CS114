#include <stdio.h>

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 6, 7};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int i = 0, j = 0;
    
    printf("Intersection of arrays: ");
    
    while (i < n1 && j < n2) {
        if (i > 0 && arr1[i] == arr1[i - 1]) {
            i++;
            continue;
        }
        if (j > 0 && arr2[j] == arr2[j - 1]) {
            j++;
            continue;
        }
        
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr1[i]) {
            j++;
        } else {
            printf("%d ", arr1[i]);
            i++;
            j++;
        }
    }
    
    printf("\n");
    return 0;
}