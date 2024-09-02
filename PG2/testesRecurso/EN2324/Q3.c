#include <stdio.h>
#include <ctype.h>
#include <string.h>

void mnemonic( char *str )
{
    char *token = strtok(str, " ");
    if(token == NULL) return;

    int index = strlen(token);

    strcpy(str, token);

    str[index++] = ' ';

    while((token = strtok(NULL, " ")) != '\0')
    {
        str[index++] = toupper(*token);
    }
    str[index] = '\0';
}


int main() {
    char str[] = "      JoRDaO BRuNO WIezel ";

    printf("Before:%s\n", str);
    mnemonic(str);
    printf("After:%s\n", str);


    return 0;
}