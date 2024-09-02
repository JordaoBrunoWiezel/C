#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int verifyWord(char *word, char *phrase)
{
    char *phrase_copy = strdup(phrase);
    if(phrase_copy == NULL) return NULL;

    char *delim = " \t\n\r\v\f";
    
    char *token = strtok(phrase_copy, delim);
    if(token == NULL) {free(phrase_copy); return NULL;}

    if(strcmp(token, word) == 0) return 1;

    while((token=strtok(NULL, delim)) != NULL)
    {
        if(strcmp(token, word) == 0) return 1;
    }
return 0;
}