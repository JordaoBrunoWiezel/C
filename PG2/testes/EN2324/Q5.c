#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
 char *desc; // descrição - string alojada dinamicamente
 int year; // ano
 short month; // mês
 short day; // dia
}Event;

// Exemplos: “Pg2 - 1.º teste parcial: 2023-11-10”

/* destinada a separar e identificar os dados de um evento, contidos na string indicada por text,
criando uma réplica da descrição, em alojamento dinâmico, e afetando as variáveis indicadas por
yPtr, mPtr e dPtr, respetivamente, com os valores de ano, mês e dia. Em caso de sucesso,
retorna a réplica da string de descrição criada; se ocorrer insucesso, devido a conteúdo de text
incompleto, retorna NULL. Neste caso, deve terminar sem deixar espaço inadequadamente
alojado.
Por simplificação, não se pretende que verifique se os valores da data pertencem às respetivas
gamas de validade. 
*/

char *eventSplit(char *text, int *yPtr, int *mPtr, int *dPtr)
{

char *text_copy = strdup(text);
if (text_copy == NULL) return NULL;

char *token = strtok(text_copy, ":");
if(token == NULL) {free(text_copy); return NULL;}

char *delim = ":/.- ";

char *aux = strtok(NULL, delim);
if(aux == NULL) {free(text_copy); return NULL;}
*yPtr = atoi(aux);

aux = strtok(NULL, delim);
if(aux == NULL) {free(text_copy); return NULL;}
*mPtr = atoi(aux);

aux = strtok(NULL, delim);
if(aux == NULL) {free(text_copy); return NULL;}
*dPtr = atoi(aux);

token = strdup(token);
free(text_copy);
return token;
}


/* destinada a criar, em alojamento dinâmico, um elemento Event preenchido com os dados obtidos
da string text. A função retorna o endereço do elemento criado ou NULL, em caso de insucesso.
Neste caso, a função não deve deixar espaço inadequadamente alojado. Deve utilizar a função
eventSplit. 
*/

Event *eventCreate(char *text)
{
    Event *e = (Event *) malloc (sizeof(*e));
    if(e == NULL) return NULL;

    e->desc = eventSplit(text, &e->year, &e->month, &e->day);

    if(e->desc == NULL) {free(e); return NULL;}

    return e;
}

/*Com o propósito de adicionar anotações à descrição de um evento, escreva a função
void eventDescAppend(Event *event, char *str);
que modifica o campo desc da struct indicada por event, adicionando, no final da string
existente, o texto indicado por str. Deve usar a função de biblioteca adequada para assegurar o
espaço necessário ao novo conteúdo da string.*/

void eventDescAppend(Event *event, char *str)
{
    // A função realloc permite realocar nova memória para uma variável, permitindo assim, por exemplo, contrair ou expandir um array.
    char *aux = realloc(event->desc, strlen(event->desc)+strlen(str)+1);
    if(aux == NULL) return;

    event->desc = aux;

    strcat(event->desc, str);
}