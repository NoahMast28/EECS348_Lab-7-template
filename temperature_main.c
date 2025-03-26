#include "temperature.h"

int main() {
    float temperature;
    char input_scale, target_scale;

    printf("Enter a temperature value: ");

    if (scanf("%f", &temperature) != 1) {
        printf("Invalid input. Please enter a floating point value.\n");
        return 1;
    }

    printf("Enter the input scale: ");
    scanf("%c", input_scale);

    printf("Enter the target scale: ");
    scanf("%c", target_scale);

    float converted_temperature;

    if (input_scale == 'C' || input_scale == 'c') {
        if (target_scale == 'F' || target_scale == 'f') {
            converted_temperature = celsius_to_fahrenheit(temperature);
        } else if (target_scale == 'K' || target_scale == 'k') {
            converted_temperature = celsius_to_kelvin(temperature);
        } else {
            printf("Invalid target temperature scale.\n");
            return 1;
        }
    } else if (input_scale == 'F' || input_scale == 'f') {
        if (target_scale == 'C' || target_scale == 'c') {
            converted_temperature = fahrenheit_to_celsius(temperature);
        } else if (target_scale == 'K' || target_scale == 'k') {
            converted_temperature = fahrenheit_to_kelvin(temperature);
        } else {
            printf("Invalid target temperature scale.\n");
            return 1;
        }
    } else if (input_scale == 'K' || input_scale == 'k') {
        if (target_scale == 'F' || target_scale == 'f') {
            converted_temperature = kelvin_to_fahrenheit(temperature);
        } else if (target_scale == 'C' || target_scale == 'c') {
            converted_temperature = kelvin_to_celsius(temperature);
        } else {
            printf("Invalid target temperature scale.\n");
            return 1;
        }
    } else {
        printf("Invalid input scale.\n");
        return 1;
    }

    float celsius_temp;
    if (input_scale == 'F' || input_scale == 'f') {
        celsius_temp = fahrenheit_to_celsius(temperature);
    } else if (input_scale == 'K' || input_scale == 'k') {
        celsius_temp = kelvin_to_celsius(temperature);
    } else {
        celsius_temp = temperature;
    }

    printf("Converted Temperature: %.2f %c\n", converted_temperature, target_scale);
    categorize_temperature(celsius_temp);

    return 0;
}
