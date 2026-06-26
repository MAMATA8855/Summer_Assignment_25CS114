#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count[256] = {0};
    int i = 0;
    char result = '\0';

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (str[i] != '\n') {
            count[(unsigned char)str[i]]++;
        }
        i++;
    }

    i = 0;
    while (str[i] != '\0') {
        if (str[i] != '\n' && count[(unsigned char)str[i]] == 1) {
            result = str[i];
            break;
        }
        i++;
    }

    if (result != '\0') {
        printf("The first non-repeating character is: '%c'\n", result);
    } else {
        printf("All characters are repeating or the string is empty.\n");
    }

    return 0;
}
