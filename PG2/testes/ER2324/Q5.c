#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct{
 int code; // Código de reserva
 char start[3+1]; // Aeroporto de partida
 char end[3+1]; // Aeroporto de chegada
 char *desc; // Descrição do voo (string alojada dinamicamente)
} Flight; 

char *break_flight(char *text, int *code, char *start, char *end)
{
    if (text == NULL || code == NULL || start == NULL || end == NULL)
        return NULL;

    char *text_copy = strdup(text);
    if(text_copy == NULL) return NULL;

    char *delim = "|-";

    char *token = strtok(text_copy, delim);
    if(token == NULL) {free(text_copy); return NULL;}
    *code = atoi(token);
    
    token = strtok(NULL, delim);
    if(token == NULL) {free(text_copy); return NULL;}
    strcpy(start,token);

    token = strtok(NULL, delim);
    if(token == NULL) {free(text_copy); return NULL;}
    strcpy(end,token);

    token = strtok(NULL, "|"); //Tive q fazer mais um para o token apontar para a descrição que fica no final, usamos | PQ DEUS QUIS
    if (token == NULL) {free(text_copy); return NULL;}

    char *descricao = strdup(token);
    if(descricao == NULL) return NULL;
    free(text_copy);
    return token;
}

/*destinada a criar, em alojamento dinâmico, um elemento Flight preenchido com os dados
obtidos da string text. A função retorna o endereço do elemento criado ou NULL, em caso de
insucesso. Neste caso, a função não deve deixar espaço inadequadamente alojado. Deve utilizar
a função break_flight. 
*/

Flight *create_flight(char *text)
{
    Flight *f = (Flight *) malloc(sizeof(*f));
    if(f == NULL) return NULL;

    f->desc = break_flight(text, &f->code, f->start, f->end);
    if(f->desc == NULL) {free(f);return NULL;}

    return f;
}

/*que modifica o campo desc da estrutura indicada por flight, adicionando, no final da string
existente, o texto indicado por duration. Deve usar a função de biblioteca adequada para
assegurar o espaço necessário ao novo conteúdo da string.
Exemplo:
No voo com a descrição “Lisboa -> Funchal”, depois de invocada a função
append_flight com a estrutura e o tempo estimado de voo “2 horas e 10 min”, a string
do campo desc deverá conter “Lisboa -> Funchal [2 horas e 10 min]
*/

void append_flight(Flight *flight, char *duration)
{
    char *aux = realloc(flight->desc, strlen(flight->desc)+strlen(duration)+strlen(" [")+strlen("]")+1);
    if(aux == NULL) return;

    flight->desc = aux;

    strcat(flight->desc, " [");
    strcat(flight->desc, duration);
    strcat(flight->desc, "]");
}