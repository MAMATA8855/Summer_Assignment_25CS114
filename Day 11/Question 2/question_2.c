#include <stdio.h>

int find_max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    int first = 45;
    int second = 82;
    int highest;

    highest = find_max(first, second);
    printf("The maximum number is: %d\n", highest);

    return 0;
}
