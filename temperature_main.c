#include "temperature.h"
#include <stdio.h>

int main() {
    // Initializes variables
    float temperature;
    char input_scale, target_scale;
    int found_error = 0;

    while (1) {
        // Gets a temperature from the user; halts processing if value is invalid
        printf("Enter a temperature value: ");
        if (scanf("%f", &temperature) != 1) {
            printf("Error: Invalid input. Please enter a floating point value.\n");

            found_error++;
        }
        while (getchar() != '\n'); // Clears input buffer

        // Does not ask user for scales if the temperature value is invalid
        if (found_error == 0) {
            // Gets the input scale from the user
            printf("Enter the input scale: ");
            scanf("%c", &input_scale);
            while (getchar() != '\n'); // Clears input buffer

            // Gets the target scale from the user
            printf("Enter the target scale: ");
            scanf("%c", &target_scale);
            while (getchar() != '\n'); // Clears input buffer
        }

        float converted_temperature;

        // Checks if the scale is Celsius and converts it to the proper scale
        if (input_scale == 'C' || input_scale == 'c') {
            if (target_scale == 'F' || target_scale == 'f') {
                converted_temperature = celsius_to_fahrenheit(temperature);
            } else if (target_scale == 'K' || target_scale == 'k') {
                converted_temperature = celsius_to_kelvin(temperature);
            } else if (target_scale == 'C' || target_scale == 'c') {
                converted_temperature = temperature;
            } else {
                printf("Error: Invalid target temperature scale.\n");
                found_error++;
            }
        }

        // Checks if the scale is Fahrenheit and converts it to the proper scale
        else if (input_scale == 'F' || input_scale == 'f') {
            if (target_scale == 'C' || target_scale == 'c') {
                converted_temperature = fahrenheit_to_celsius(temperature);
            } else if (target_scale == 'K' || target_scale == 'k') {
                converted_temperature = fahrenheit_to_kelvin(temperature);
            } else if (target_scale == 'F' || target_scale == 'f') {
                converted_temperature = temperature;
            } else {
                printf("Error: Invalid target temperature scale.\n");
                found_error++;
            }
        }

        // Checks if the scale is Kelvin and converts it to the proper scale
        else if (input_scale == 'K' || input_scale == 'k') {
            if (temperature < 0) {
                printf("Error: Cannot have a negative temperature in Kelvin.\n");
                found_error++;
            } else if (target_scale == 'F' || target_scale == 'f') {
                converted_temperature = kelvin_to_fahrenheit(temperature);
            } else if (target_scale == 'C' || target_scale == 'c') {
                converted_temperature = kelvin_to_celsius(temperature);
            } else if (target_scale == 'K' || target_scale == 'k') {
                converted_temperature = temperature;
            } else {
                printf("Error: Invalid target temperature scale.\n");
                found_error++;
            }
        }

        // Informs the user that the input scale was invalid and increments found_error
        else {
            // If a previous error occured, prevents another error message from appearing
            if (found_error == 0) {
                printf("Error: Invalid input scale.\n");

                found_error++;
            }
        }

        if (found_error == 0) {
            // Converts the given temperature to celsius so that we can call categorize_temperature
            float celsius_temp;
            if (input_scale == 'F' || input_scale == 'f') {
                celsius_temp = fahrenheit_to_celsius(temperature);
            } else if (input_scale == 'K' || input_scale == 'k') {
                celsius_temp = kelvin_to_celsius(temperature);
            } else {
                celsius_temp = temperature;
            }

            // Prints the converted temperature and calls categorize_temperature
            printf("Converted Temperature: %.2f %c\n", converted_temperature, target_scale);
            categorize_temperature(celsius_temp);

            return 0;
        } else {
            // Asks the user if they want to re-enter values or exit the program
            char user_choice = 0;
            printf("Enter 1 to re-enter values or 0 to exit the program: ");
            scanf("%c", &user_choice);

            // Exits the program if user enters 1
            if (user_choice != '1') {
                return 1;
            }

            found_error = 0; // Sets found_error back to zero
        }
    }
}
