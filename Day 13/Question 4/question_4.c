#include <stdio.h>

int main() {
    int n;
    int even_count = 0;
    int odd_count = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(int i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }
    
    printf("Total even elements = %d\n", even_count);
    printf("Total odd elements = %d\n", odd_count);
    
    return 0;
}
