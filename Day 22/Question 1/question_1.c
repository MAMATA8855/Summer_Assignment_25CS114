#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int left = 0;
    int right;
    int is_palindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    right = strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            is_palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (is_palindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
