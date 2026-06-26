#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    char compressed[200];
    int i = 0;
    int j = 0;
    int count;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    while (str[i] != '\0') {
        count = 1;
        while (str[i] == str[i + 1]) {
            count++;
            i++;
        }
        
        compressed[j++] = str[i];
        j += sprintf(&compressed[j], "%d", count);
        i++;
    }
    compressed[j] = '\0';

    if (strlen(compressed) >= strlen(str)) {
        printf("Compressed string: %s\n", str);
    } else {
        printf("Compressed string: %s\n", compressed);
    }

    return 0;
}
