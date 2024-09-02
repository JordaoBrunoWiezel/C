#include <stdio.h>

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

char *eventSplit(char *text, int *yPtr, int *mPtr, int *dPtr) {
    
    char *text_copy = strdup(text);
    if(text_copy == NULL) return NULL;

    char *token = strtok(text_copy, ":");
    if(token == NULL) {free(text_copy);return NULL;}

    char *delim = "/-. ";

    char *year = strtok(NULL, delim);
    if(year == NULL) {free(text_copy); return NULL;}
    *yPtr = atoi(year);

    char *month = strtok(NULL, delim);
    if(month == NULL) {free(text_copy); return NULL;}
    *mPtr = atoi(month);

    char *day = strtok(NULL, delim);
    if(day == NULL) {free(text_copy); return NULL;}
    *dPtr = atoi(day);

    char *desc = strdup(token);
    free(text_copy);
    return desc;     
}

Event *eventCreate(char *text)
{
    Event *e = (Event*)malloc(sizeof(*e));
    if(e == NULL) return NULL;

    e->desc = eventSplit(text, &e->year, &e->month, &e->day);
    if(e->desc == NULL)  {free(e);return NULL;}

    return e;

}

int compareEventDate(Event *event1, Event *event2)
{
    if(event1->year != event2->year){
        return event1->year - event2->year;
    } else if(event1->month != event2->month){
        return event1->month-event2->month;
    } else
        return event1->day-event2->day;
} 

int listInsert(ListEvPtr **headAddr, char *text)
{
    Event *newEvent = eventCreate(text); // novo elemento com os dados obtidos de text e inseri-lo
    if(newEvent == NULL) return 0;

    ListEvPtr *newnode = (ListEvPtr*)malloc(sizeof(*newnode)); // criar um novo nó
    if(newnode == NULL) {free(newEvent->desc);free(newEvent); return 0;}

    newnode->ptr = newEvent; // Isso garante que o novo nó de lista aponte para o evento criado.
    newnode->next = NULL;
    ListEvPtr **current = headAddr;

    while ((*current != NULL) && compareEventDate((*current)->ptr, newnode->ptr) < 0) {
        current = &((*current)->next);
    }
    newnode->next = *current;
    *current = newnode;

return 1;
} 
