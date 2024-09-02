#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <strings.h>

int     lineParse(char *text, int *number, char *name, char *job)
{
    char delim[] = ";";
    char *token = strtok(text, delim);

    if (token == NULL) return 0;

    *number = atoi(token);

    if((token = strtok(NULL, delim)) == NULL) return 0;

    strcpy(name, token);

    if((token = strtok(NULL, delim)) == NULL) return 0;

    strcpy(job, token);

return 1;
}

int main()
{
    char arr[3][100] = {"123; Manuel Arruda; Presidente",
                        "234; Joaquim Salvaterra; Tesoreiro",
                        "246; Arlindo do Vale; Vogal"
                        };

    char nome[100], prof[100];
    int id;
    for(int i = 0; i < 3; i++)
    {
    lineParse(arr[i], &id, )
    }
}