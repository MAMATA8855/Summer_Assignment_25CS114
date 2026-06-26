#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count[256] = {0};
    int i = 0;
    int max = 0;
    char max_char = '\0';

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (str[i] != '\n' && str[i] != ' ') {
            count[(unsigned char)str[i]]++;
        }
        i++;
    }

    for (i = 0; i < 256; i++) {
        if (count[i] > max) {
            max = count[i];
            max_char = (char)i;
        }
    }

    if (max > 0) {
        printf("The maximum occurring character is '%c' (appears %d times).\n", max_char, max);
    } else {
        printf("No valid characters found.\n");
    }

    return 0;
}
