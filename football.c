#include "football.h"
#include <stdio.h>

// Counts the number of combinations for a given point value
int count_combinations(int points) {
    int count = 0;

    // The code for this looks a bit absurd, however the logic isn't that complicated
    // Brute force checks each possible combination and increments count if it adds up to the right number of points
    for (int td_2 = 0; td_2 * 8 <= points; td_2++) {
        for (int td_fg = 0; td_fg * 7 <= points; td_fg++) {
            for (int td = 0; td * 6 <= points; td++) {
                for (int fg = 0; fg * 3 <= points; fg++) {
                    for (int safety = 0; safety * 2 <= points; safety++) {
                        if ((td_2 * 8) + (td_fg * 7) + (td * 6) + (fg * 3) + (safety * 2) == points) {
                            count++;
                        }
                    }
                }
            }
        }
    }

    return count;
}

// Prints each possible combination of scoring plays for a given point value
void print_combinations(int points) {
    // Brute force checks each possible combination and prints if the plays add up to the right number of points
    for (int td_2 = 0; td_2 * 8 <= points; td_2++) {
        for (int td_fg = 0; td_fg * 7 <= points; td_fg++) {
            for (int td = 0; td * 6 <= points; td++) {
                for (int fg = 0; fg * 3 <= points; fg++) {
                    for (int safety = 0; safety * 2 <= points; safety++) {
                        if ((td_2 * 8) + (td_fg * 7) + (td * 6) + (fg * 3) + (safety * 2) == points) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_2, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }

    printf("\n"); // Prints new line for formatting
}