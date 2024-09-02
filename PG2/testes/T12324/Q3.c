#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *uniformize( char *str )
{
    int i = 0, j = 0;

    while(str[i] != '\0')
    {
        if(isalnum(str[i]))
        {
            str[j] = toupper(str[i]);
            j++;
        }
    i++;
    }
    str[j] = '\0';

return str;
}

int main()
{
    char palavra[] = "ADEJ   ***  AN 4141jne1o hb";

    printf("Placa formatada: %s\n", uniformize(palavra));
}