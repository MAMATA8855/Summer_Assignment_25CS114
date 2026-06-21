#include <stdio.h>

int main() {
    char str[100];
    char reversed[100];
    int length = 0;
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[length] != '\0') {
        length++;
    }

    for (i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';

    printf("Reversed string: %s\n", reversed);

    return 0;
}
