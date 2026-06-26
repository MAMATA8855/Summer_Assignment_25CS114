#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i = 0;
    int j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';

    printf("String after removing spaces: %s\n", str);

    return 0;
}