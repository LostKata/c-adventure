#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_LENGTH 10  // Define a larger buffer for safety

char line[MAX_INPUT_LENGTH];

int main() {
    srand(time(NULL));
    int r = rand() % 100 + 1;  // Generates a random number between 1 and 100
    printf("Random number generated (for testing): %d\n", r);
    printf("Guess a number between 1 and 100:\n");

    while(1) {
        printf("Enter your guess: ");
        if (fgets(line, sizeof(line), stdin) != NULL) {
            int guess;
            int ret = sscanf(line, "%d", &guess);

            if (ret != 1) {
                printf("Invalid input. Please enter a valid integer.\n");
                continue;
            }

            if (guess < 1 || guess > 100) {
                printf("Your guess is out of range. Please enter a number between 1 and 100.\n");
                continue;
            }

            if (r == guess) {
                printf("Congratulations! You guessed the correct number: %d\n", guess);
                break;
            } else if (guess < r) {
                printf("Too low! Try again.\n");
            } else {
                printf("Too high! Try again.\n");
            }
        } else {
            printf("Error reading input. Please try again.\n");
        }
    }
    
    return 0;
}
