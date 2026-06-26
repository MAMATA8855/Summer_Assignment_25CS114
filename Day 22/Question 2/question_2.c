#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int i = 0;
    int words = 0;
    int in_word = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            words++;
        }
        i++;
    }

    printf("Total words: %d\n", words);

    return 0;
}
