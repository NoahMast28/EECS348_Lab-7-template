#include "temperature.h"
#include <stdio.h>

int main() {
    // Initializes variables
    float temperature;
    char input_scale, target_scale;

    // Gets a temperature from the user; halts processing if value is invalid
    printf("Enter a temperature value: ");
    if (scanf("%f", &temperature) != 1) {
        printf("Invalid input. Please enter a floating point value.\n");
        return 1;
    }

    // Gets the input scale from the user
    printf("Enter the input scale: ");
    scanf("%c", input_scale);

    // Gets the target scale from the user
    printf("Enter the target scale: ");
    scanf("%c", target_scale);

    float converted_temperature; // Initializes converted_temperature

    // Checks if the scale is Celsius and converts it to the proper scale
    if (input_scale == 'C' || input_scale == 'c') {
        if (target_scale == 'F' || target_scale == 'f') {
            converted_temperature = celsius_to_fahrenheit(temperature);
        } else if (target_scale == 'K' || target_scale == 'k') {
            converted_temperature = celsius_to_kelvin(temperature);
        } else if {
            converted_temperature = temperature;
        } else {
            printf("Invalid target temperature scale.\n");
            return 1;
        }
    }

    // Checks if the scale is Fahrenheit and converts it to the proper scale
    else if (input_scale == 'F' || input_scale == 'f') {
        if (target_scale == 'C' || target_scale == 'c') {
            converted_temperature = fahrenheit_to_celsius(temperature);
        } else if (target_scale == 'K' || target_scale == 'k') {
            converted_temperature = fahrenheit_to_kelvin(temperature);
        } else if {
            converted_temperature = temperature;
        } else {
            printf("Invalid target temperature scale.\n");
            return 1;
        }
    }

    // Checks if the scale is Kelvin and converts it to the proper scale
    else if (input_scale == 'K' || input_scale == 'k') {
        if (target_scale == 'F' || target_scale == 'f') {
            converted_temperature = kelvin_to_fahrenheit(temperature);
        } else if (target_scale == 'C' || target_scale == 'c') {
            converted_temperature = kelvin_to_celsius(temperature);
        } else if {
            converted_temperature = temperature;
        } else {
            printf("Invalid target temperature scale.\n");
            return 1;
        }
    }

    // Informs the user that the input scale was invalid
    else {
        printf("Invalid input scale.\n");
        return 1;
    }

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
}
