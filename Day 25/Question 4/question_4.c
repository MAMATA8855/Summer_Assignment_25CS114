#include <stdio.h>
#include <string.h>

int main() {
    int n;

    printf("Enter the number of words: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }
    getchar();

    char words[n][100];

    for (int i = 0; i < n; i++) {
        printf("Enter word %d: ", i + 1);
        fgets(words[i], sizeof(words[i]), stdin);
        words[i][strcspn(words[i], "\n")] = '\0';
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strlen(words[j]) > strlen(words[j + 1])) {
                char temp[100];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
