#include <stdio.h>

int main() {
    int size;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    int matrix[size][size];
    int main_sum = 0;
    int side_sum = 0;

    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < size; i++) {
        main_sum += matrix[i][i];
        side_sum += matrix[i][size - 1 - i];
    }

    printf("\nSum of primary diagonal: %d\n", main_sum);
    printf("Sum of secondary diagonal: %d\n", side_sum);

    return 0;
}
