#include <stdio.h>
#include <string.h>

int main() {
    char str1[200];
    char str2[100];
    char temp[200];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    if (strlen(str1) != strlen(str2)) {
        printf("The second string is not a rotation of the first string.\n");
        return 0;
    }

    strcpy(temp, str1);
    strcat(temp, str1);

    if (strstr(temp, str2) != NULL) {
        printf("The second string is a rotation of the first string.\n");
    } else {
        printf("The second string is not a rotation of the first string.\n");
    }

    return 0;
}

