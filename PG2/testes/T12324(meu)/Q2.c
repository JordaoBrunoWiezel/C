#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int copyWord( const char *source, int order, char *dest )
{
    char *source_copy = strdup(source);
    if(source_copy == NULL) return 0;

    char *token = strtok(source_copy, " ");
    if(token == NULL) {free(source_copy); return 0;}

    if(order == 1){
        strcpy(dest, token);
        return 1;
    }

    int count = 1; // Para contar o numero de palavras;

    while((token = strtok(NULL, " ")) != NULL)
    {
        count++;

        if(order == count)
        {
            int i = 0;
            while(token[i] != '\0')
            {
                dest[i] = tolower(token[i]);
                i++;
            }
            dest[i] = '\0';
            return 1;
        }
    }

    free(source_copy);
    return 0;
}

int main() {

    char source[] = "Hello World This is a Test";
    char dest[100];
    int order = 3;

    if (copyWord(source, order, dest)) {
        printf("Palavra copiada: %s\n", dest);
    } else {
        printf("Erro: Palavra não encontrada\n");
    }

    return 0;
}