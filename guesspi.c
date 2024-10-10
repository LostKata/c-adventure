#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int n = 100000;
    int count_inside_circle = 0;
    int count_outside_circle = 0;

    // Loop through n times
    for (int i = 0; i < n; i++) {
        // Generate random x and y coordinates between 0 and 1
        float x = (float)rand() / RAND_MAX;
        float y = (float)rand() / RAND_MAX;

        // Check if the point (x, y) is inside the quarter circle
        if (x * x + y * y <= 1) {
            count_inside_circle++;
        } else {
            count_outside_circle++;
        }
    }

    // Estimate the value of pi
    float pi_estimate = 4.0 * (float)count_inside_circle / n;

    // Print the results
    printf("Points inside the circle: %d\n", count_inside_circle);
    printf("Points outside the circle: %d\n", count_outside_circle);
    printf("Total points: %d\n", n);
    printf("Estimated Pi: %f\n", pi_estimate);

    return 0;
}
