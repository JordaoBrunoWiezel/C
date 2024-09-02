#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int countWords(const char *string, int *storeLongestSize) {
    int wordCount = 0;
    int maxWordLength = 0;
    int currentWordLength = 0;
    int inWord = 0, i = 0;

    while (string[i] != '\0') {
        if (isalnum((unsigned char)string[i]) || string[i] == '-') {
            if (inWord == 0) {
                inWord = 1;
                wordCount++;
                currentWordLength = 1;
            } else {
                currentWordLength++;
            }
        } else {
            if (inWord == 1) {
                if (currentWordLength > maxWordLength) {
                    maxWordLength = currentWordLength;
                }
                inWord = 0;
            }
        }
        i++;
    }

    if ((inWord == 1) && currentWordLength > maxWordLength) {
        maxWordLength = currentWordLength;
    }

    if (storeLongestSize != NULL) {
        *storeLongestSize = maxWordLength;
    }

    return wordCount;
}