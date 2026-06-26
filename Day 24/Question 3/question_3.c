#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char longest[100];
    int i = 0;
    int start = 0;
    int max_len = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            i++;
        }
        
        if (str[i] == '\0') {
            break;
        }

        int current_start = i;
        int current_len = 0;

        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            current_len++;
            i++;
        }

        if (current_len > max_len) {
            max_len = current_len;
            start = current_start;
        }
    }

    strncpy(longest, &str[start], max_len);
    longest[max_len] = '\0';

    printf("The longest word is: %s\n", longest);

    return 0;
}


