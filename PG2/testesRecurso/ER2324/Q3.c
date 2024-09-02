#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* com strtok (nao é bem isso q pede)
char *firstUpper( char *str )
{
    int i = 0;
    while(str[i] != '\0'){ 
        str[i] = tolower(str[i]);
        i++;
    }

    char *delim = " \t\n\r\v\f";

    char *token = strtok(str, delim);
    if(token == NULL) return NULL;

    int index = strlen(token); // fica 6 jordao

    strcpy(str, token);

    *str = toupper(*str); // tira o espaço inicial

    str[index++] = ' '; //adiciona 1 espaço

    while((token = strtok(NULL, delim)) != NULL)
    {
        str[index++] = toupper(*token);
        int j = 1;
        while(token[j] != '\0')
            str[index++] = token[j++];
        str[index++] = ' ';
    }
    str[index] = '\0';

    return str;
}
*/

char *firstUpper(char *str)
{
    int WordStarted = 0, i = 0;
    char *index = NULL; // apenas para guardar o primeiro caracter da primeira palavra

    while(str[i] != '\0')
    {
        if(!isspace(str[i])) //se achar uma letra
        {
            if(WordStarted == 0) // a palavra ja começou?
            {
                str[i] = toupper(str[i]); // Poe a primeira letra a maisculo

                if(index == 0) // o index (primeiro caracter) ja foi guardado?
                {
                   index = &str[i];

                }
            WordStarted = 1; // Aviso que ja estamos em uma palavra
            } 
            else // se a palabra ja começou, ja nao é a primeira
            {
                str[i] = tolower(str[i]); // poe para minusculo
            }
        }
        else // se não houver uma letra
        {
            WordStarted = 0;
        }
        i++;
    }
    return index != NULL? index:&str[i]; // nao percebi se ele quer q retorne o endereço do terminador e sua localização (indice) caso nao haja palavras
}

int main() {
    char str[] = "      JoRDaO BRuNO WIezel ";

    printf("Before:%s\n", str);
    firstUpper(str);
    printf("After:%s\n", str);


    return 0;
}