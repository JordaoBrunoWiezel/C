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

typedef struct listEvPtr{
 struct listEvPtr *next;
 Event *ptr;
} ListEvPtr;

/*que compara as datas de dois eventos, retornando um valor negativo, zero ou positivo se,
respetivamente, a data de event1 for anterior, igual ou posterior à de event2
*/
int compareEventDate(Event *event1, Event *event2)
{
    if(event1->year != event2->year) return event1->year - event2->year;
    else if(event1->month != event2->month) return event1->month - event2->month;
    else if(event1->day != event2->day) return event1->day - event2->day;

return 0;
}

/*destinada a criar um novo elemento com os dados obtidos de text e inseri-lo, ordenado, na lista
cujo ponteiro cabeça é indicado por headAddr. Em caso de sucesso, retorna 1; se falhar a criação
do evento, não deve modificar a lista e retorna 0. Deve usar as funções compareEventDate e
eventCreate. 
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

Event *eventCreate(char *text) // Função que cria um novo evento a partir de uma string de texto
{
    Event *e = (Event *) malloc (sizeof(*e));
    if(e == NULL) return NULL;

    e->desc = eventSplit(text, &e->year, &e->month, &e->day); //na estrutura, month e day sao short :/

    if(e->desc == NULL) {free(e); return NULL;}

    return e;
}

/* destinada a criar um novo elemento com os dados obtidos de text e inseri-lo, ordenado, na lista
cujo ponteiro cabeça é indicado por headAddr. Em caso de sucesso, retorna 1; se falhar a criação
do evento, não deve modificar a lista e retorna 0. Deve usar as funções compareEventDate e
eventCreate
*/

int listInsert(ListEvPtr **headAddr, char *text) // Wata foqui is dis xit
{

    Event *newEvent = eventCreate(text);
    if(newEvent == NULL) return 0;

    ListEvPtr *newNode = (ListEvPtr *) malloc (sizeof(*newNode));
    if(newNode == NULL) {free(newEvent->desc); free(newEvent); return 0;}

    ListEvPtr **current = headAddr;
    while(*current != NULL && compareEventDate((*current)->ptr, newEvent) < 0)
        current = &((*current)->next);

    newNode->next = *current;
    *current = newNode;

return 1;
}