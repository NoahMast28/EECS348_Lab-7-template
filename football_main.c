#include "football.h"
#include <stdio.h>

int main() {
    int points;

    // Executes until the user enters a 0 or 1 to exit
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");

        // Prints an error if the user does not input an integer or if their integer is negative
        if (scanf("%d", &points) != 1 || points < 0) {
            printf("Invalid input. Enter a nonnegative integer.\n\n");

            while (getchar() != '\n');
        }

        // Exits the loop if the user entered 0 or 1
        else if (points == 0 || points == 1) {
            break;
        }

        // Prints the total number of combinations and the combinations
        else {
            printf("Total combinations: %d\n", count_combinations(points));
            print_combinations(points);
        }
    }
    
    return 0;
}