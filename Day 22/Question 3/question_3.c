#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int count[256] = {0};
    int i = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (str[i] != '\n') {
            count[(unsigned char)str[i]]++;
        }
        i++;
    }

    printf("Character frequencies:\n");
    for (i = 0; i < 256; i++) {
        if (count[i] > 0) {
            printf("'%c': %d\n", i, count[i]);
        }
    }

    return 0;
}
