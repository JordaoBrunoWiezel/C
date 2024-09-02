#include <stdio.h>
#include <string.h>


typedef struct{
 char *desc; // descrição - string alojada dinamicamente
 int year; // ano
 short month; // mês
 short day; // dia
}Event; 

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

void eventDescAppend(Event *event, char *str)
{
    char* aux = realloc(event->desc, strlen(event->desc)+strlen(str)+1);
    if(aux == NULL) return NULL;

    event->desc = aux;

    strcat(event->desc, str);
}
