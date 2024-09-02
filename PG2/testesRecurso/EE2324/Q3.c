#include <stdio.h>
#include <ctype.h>
#include <string.h>

int verifyWord(char *word, char *phrase)
{
    char *delim = " \t\n\r\v\f";
    char *token = strtok(phrase, delim);
    if(token == NULL) return 0;

    if(strcmp(token, word) == 0) return 1;

    while((token = strtok(NULL, delim)) != NULL)
    {
        if(strcmp(token, word)== 0)
        {
            return 1;
        }
    }
    return 0;
}