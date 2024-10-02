#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char line[5];

int main() {
    srand(time(NULL));
    int r = rand() % 100 + 1;
    printf("r %d\n", r);
    printf("guess a number between 0 and 100\n");
    while(1) {
        fgets(line, sizeof(line), stdin);
        int guess;
        int ret = sscanf(line, "%d", &guess);
        
        if (ret != 1) {
            printf("Invalid input. Please enter a valid integer.\n")
            continue;
        }
        
        printf("ret %d\n", ret);
        printf("guess %d\n", guess);
        printf("\n");
        if (r == guess) {
            printf("You guessed it\n");
            break;
        } else {
            printf("Try again\n");
            continue;
        }
        

    }
    return 0;
}