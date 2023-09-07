#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to count the number of words in a given text
int countWords(const char *text) {
    int wordCount = 0;
    bool inWord = false;

    int textLength = strlen(text);
    for (int i = 0; i < textLength; i++) {
        // Check if the current character is a space or a punctuation mark
        if (text[i] == ' ' || text[i] == '\t' || text[i] == '\n' || text[i] == '\r' || text[i] == '.' || text[i] == ',' || text[i] == '!' || text[i] == '?' || text[i] == ';' || text[i] == ':') {
            inWord = false;
        } else if (!inWord) {
            // If the current character is not a space and we were not in a word before, increment the word count
            inWord = true;
            wordCount++;
        }
    }

    return wordCount;
}

int main() {
    char *text = NULL;
    size_t bufferSize = 1000;
    size_t textLength;

    // Allocate memory for the input text
    text = (char *)malloc(bufferSize * sizeof(char));

    if (text == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the text
    printf("Enter a text or sentence (press Enter to finish):\n");
    getline(&text, &bufferSize, stdin);

    // Remove the newline character from getline
    textLength = strlen(text);
    if (textLength > 0 && text[textLength - 1] == '\n') {
        text[textLength - 1] = '\0';
    }

    // Count the words in the text
    int wordCount = countWords(text);

    // Print the word count
    printf("Number of words in the text: %d\n", wordCount);

    // Free the dynamically allocated memory
    free(text);

    return 0;
}

