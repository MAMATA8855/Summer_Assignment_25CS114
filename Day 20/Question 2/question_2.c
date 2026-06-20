#include <stdio.h>

int main() {
    int size;
    int is_symmetric = 1;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    int matrix[size][size];

    printf("\nEnter elements of the matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                is_symmetric = 0;
                break;
            }
        }
        if (!is_symmetric) {
            break;
        }
    }

    if (is_symmetric) {
        printf("\nThe matrix is a symmetric matrix.\n");
    } else {
        printf("\nThe matrix is not a symmetric matrix.\n");
    }

    return 0;
}
