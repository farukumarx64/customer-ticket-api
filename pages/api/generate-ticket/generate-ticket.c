#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random uppercase letter
char getRandomUppercaseLetter() {
    return 'A' + (rand() % 26);
}

// Function to generate a random digit (0-9)
char getRandomDigit() {
    return '0' + (rand() % 10);
}

// Function to generate a random UUID (version 4) in the specified format
void generate_uuid(char *uuid) {
    // Generate the first section (XXX)
    uuid[0] = getRandomUppercaseLetter();
    uuid[1] = getRandomUppercaseLetter();
    uuid[2] = getRandomUppercaseLetter();
    
    // Separator '-'
    uuid[3] = '-';
    
    // Generate the second section (XXXXX)
    for (int i = 4; i < 9; ++i) {
        uuid[i] = getRandomUppercaseLetter();
    }

    // Separator '-'
    uuid[9] = '-';

    // Generate the third section (XXX)
    uuid[10] = getRandomDigit();
    uuid[11] = getRandomDigit();
    uuid[12] = getRandomDigit();

    // Null-terminate the string
    uuid[13] = '\0';
}

int main() {
    srand(time(NULL)); // Seed for random number generator

    char uuid[14]; // UUID format: XXX-XXXXX-XXX\0
    generate_uuid(uuid);

    // Print the generated UUID
    printf("%s", uuid);

    return 0;
}
