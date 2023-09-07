#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    // Input the first string
    printf("Enter the first string: ");
    scanf("%s", str1);

    // Input the second string
    printf("Enter the second string: ");
    scanf("%s", str2);

    // Compare the two strings
    int compareResult = strcmp(str1, str2);

    if (compareResult == 0) {
        printf("The two strings are the same.\n");
    } else if (compareResult > 0) {
        printf("The first string is longer as a word.\n");
    } else {
        printf("The second string is longer as a word.\n");
    }

    return 0;
}
