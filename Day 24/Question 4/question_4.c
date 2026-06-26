#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count[256] = {0};
    int i = 0;
    int j = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (str[i] != '\n') {
            if (count[(unsigned char)str[i]] == 0) {
                count[(unsigned char)str[i]] = 1;
                str[j] = str[i];
                j++;
            }
        } else {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';

    printf("String after removing duplicates: %s", str);

    return 0;
}
