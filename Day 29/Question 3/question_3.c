#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void stringLength() {
    char str[200];
    getchar();
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    printf("Length of the string: %d\n", len);
}

void stringCopy() {
    char source[200], destination[200];
    getchar();
    printf("Enter source string: ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = 0;
    
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    printf("Copied String: %s\n", destination);
}

void stringConcatenate() {
    char str1[400], str2[200];
    getchar();
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;
    
    int i = 0, j = 0;
    while (str1[i] != '\0') {
        i++;
    }
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    printf("Concatenated String: %s\n", str1);
}

void stringCompare() {
    char str1[200], str2[200];
    getchar();
    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;
    
    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;
    
    int i = 0, flag = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            flag = 1;
            break;
        }
        i++;
    }
    
    if (flag == 0 && str1[i] == '\0' && str2[i] == '\0') {
        printf("Strings are equal.\n");
    } else {
        printf("Strings are not equal.\n");
    }
}

void stringReverse() {
    char str[200], temp;
    getchar();
    printf("Enter a string to reverse: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    
    int i = 0, j = len - 1;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    printf("Reversed String: %s\n", str);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Menu-Driven String Operations ===\n");
        printf("1. Find Length of String\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Reverse String\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                stringLength();
                break;
            case 2:
                stringCopy();
                break;
            case 3:
                stringConcatenate();
                break;
            case 4:
                stringCompare();
                break;
            case 5:
                stringReverse();
                break;
            case 6:
                printf("Exiting string processing utility.\n");
                return 0;
            default:
                printf("Invalid selection. Choose an available option from the menu.\n");
        }
    }
    return 0;
}
