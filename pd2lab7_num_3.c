#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count the frequency of characters in the string
void countCharacterFrequency(const char *str, int **frequency) {
    *frequency = (int *)calloc(26, sizeof(int)); // Assuming only lowercase letters

    if (*frequency == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int strLength = strlen(str);
    for (int i = 0; i < strLength; i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            (*frequency)[c - 'a']++;
        }
    }
}

int main() {
    char inputString[1000];
    int *charFrequency;

    // Input the string
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // Remove the newline character from fgets
    if (inputString[strlen(inputString) - 1] == '\n') {
        inputString[strlen(inputString) - 1] = '\0';
    }

    // Count the character frequency
    countCharacterFrequency(inputString, &charFrequency);

    // Print the character frequencies
    printf("Character frequencies:\n");
    for (int i = 0; i < 26; i++) {
        if (charFrequency[i] > 0) {
            printf("%d '%c', ", charFrequency[i], 'a' + i);
        }
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(charFrequency);

    return 0;
}
