#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h> // Para alocar memória dinamicamente


char *uniformize(char *str)
{
    int i = 0, j = 0;
    // char *str_copy = strdup(str); // char *str_copy = (char *)malloc(strlen(str) + 1); // Aloca memória

    while (str[i] != '\0')
    {
        if (isalnum(str[i]))
        {
            str[j] = toupper(str[i]);
            j++;
        }
        i++;
    }
    str[j] = '\0'; // Adiciona o caractere nulo no final da string
    return str;
}

int main()
{
    char str[] = "    afbs--eweh/+ew.r.2331..,ef.";

    char *resp = uniformize(str);

    printf("%s\n", resp);

    // free(resp); // Libera a memória alocada
    return 0;
}
