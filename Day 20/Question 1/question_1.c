#include <stdio.h>

int main() {
    int r1, c1, r2, c2;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("\nError: Columns of first matrix must equal rows of second matrix.\n");
        return 1;
    }

    int a[r1][c1];
    int b[r2][c2];
    int product[r1][c2];

    printf("\nEnter elements of 1st matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of 2nd matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            product[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nProduct of the two matrices:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d   ", product[i][j]);
            if (j == c2 - 1) {
                printf("\n");
            }
        }
    }

    return 0;
}
