#include <stdio.h>

int main() {
    int rows, cols;
    int a[100][100], b[100][100], sum[100][100];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("\nEnter elements of 1st matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of 2nd matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nSum of the two matrices:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d   ", sum[i][j]);
            if (j == cols - 1) {
                printf("\n");
            }
        }
    }

    return 0;
}
