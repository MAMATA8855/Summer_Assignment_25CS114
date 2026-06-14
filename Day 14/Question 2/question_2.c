#include <stdio.h>

int countFrequency(int arr[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    int numbers[] = {2, 4, 6, 2, 8, 2, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int target = 2;
    
    int frequency = countFrequency(numbers, size, target);
    
    printf("The element %d appears %d times.\n", target, frequency);
    
    return 0;
}
