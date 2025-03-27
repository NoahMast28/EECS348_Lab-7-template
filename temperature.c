#include "temperature.h"
#include <stdio.h>

// Uses the given formula to convert celsius to fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * (9.0 / 5.0)) + 32;
}

// Uses the given formula to convert fahrenheit to celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * (5.0 / 9.0);
}

// Uses the given formula to convert celsius to kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

// Uses the given formula to convert kelvin to celsius
float kelvin_to_celsius(float kelvin) {

    // Checks if the temperate is negative
    if (kelvin < 0) {
        printf("Error: Kelvin temperatures cannot be negative\n");
        return -1; // Returns an error value of -1
    }

    return kelvin - 273.15;
}

// Converts fahrenheit to kelvin by converting it to celsius then kelvin
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

// Converts kelvin to fahrenheit by converting it to celsius then fahrenheit
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Prints a category and message based on the temperature given
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Category: Freezing - Wear winter gear.\n");
    } else if (celsius < 10) {
        printf("Category: Cold - Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Category: Comfortable - Enjoy the nice weather!\n");
    } else if (celsius < 35) {
        printf("Category: Hot - Make sure to drink lots of water.\n");
    } else {
        printf("Category: Extreme Heat - Avoid being outside for too long.\n");
    }
}