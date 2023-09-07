#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    char word[100];

    // Input the sentence
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character from fgets
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }

    // Input the word to search for
    printf("Enter the word to search for: ");
    scanf("%s", word);

    // Initialize variables
    int sentenceLength = strlen(sentence);
    int wordLength = strlen(word);
    int index = 0;
    int found = 0;

    // Loop through the sentence to find the word
    while (index <= sentenceLength - wordLength) {
        if (strncmp(&sentence[index], word, wordLength) == 0) {
            printf("Found at index %d\n", index);
            found = 1;
        }
        index++;
    }

    if (!found) {
        printf("Word not found in the sentence.\n");
    }

    return 0;
}