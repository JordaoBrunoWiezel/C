#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/* 1ª forma (com strtok)

char *firstUpper(char *str)
{
    int i = 0;
    while(str[i] != '\0') // ponho tudo a minusculo
    {
        str[i] = tolower(str[i]);
        i++;
    }

    char *token = strtok(str, " "); / fica Jordao\0Bruno Wiezel
    if(token == NULL) return NULL;  //  isso significa que a string original não contém nenhum token válido (ela estava vazia ou consistia apenas em delimitadores).

    int index = strlen(token); // no caso vai ser 6 (jordao)

    strcpy(str, token); //isso serve para tirar os espaços da str original

    *str = toupper(*str); // ponho a primeira letra maiscula
    
    str[index++] = ' '; //adiciono espaço

    while((token = strtok(NULL, " ")) != NULL) 
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

// 2º forma (oq a questao pede kk)

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
    char str[] = "      JoRDaO BRuNO WIezel "; // Array mutável

    printf("Before:%s\n", str);
    firstUpper(str);
    printf("After:%s\n", str);


    return 0;
}