#include <stdio.h>
#include <ctype.h>

int main() {
    char answers[3] = {'C', 'A', 'B'};
    char guess;
    int score = 0;

    printf("--- Welcome to the Quiz Application ---\n\n");

    printf("Question 1: What is the size of an int data type in C (usually)?\n");
    printf("A. 1 Byte\n");
    printf("B. 2 Bytes\n");
    printf("C. 4 Bytes\n");
    printf("D. 8 Bytes\n");
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &guess);
    if (toupper(guess) == answers[0]) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong. The correct answer was C.\n\n");
    }

    printf("Question 2: Which keyword is used to prevent modification of a variable?\n");
    printf("A. const\n");
    printf("B. static\n");
    printf("C. volatile\n");
    printf("D. immutable\n");
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &guess);
    if (toupper(guess) == answers[1]) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong. The correct answer was A.\n\n");
    }

    printf("Question 3: Which function is used to clear the input buffer in C?\n");
    printf("A. clear()\n");
    printf("B. fflush()\n");
    printf("C. clean()\n");
    printf("D. purge()\n");
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &guess);
    if (toupper(guess) == answers[2]) {
        printf("Correct!\n\n");
        score++;
    } else {
        printf("Wrong. The correct answer was B.\n\n");
    }

    printf("--- Quiz Completed! ---\n");
    printf("Your final score is: %d out of 3\n", score);

    return 0;
}
