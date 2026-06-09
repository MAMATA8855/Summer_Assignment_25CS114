#include <stdio.h>

int main() {
    int rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        
        char ch = 'A';
        for (int k = 1; k <= i; k++) {
            printf("%c", ch);
            ch++;
        }
        
        ch -= 2;
        for (int l = i - 1; l >= 1; l--) {
            printf("%c", ch);
            ch--;
        }
        
        printf("\n");
    }

    return 0;
}

