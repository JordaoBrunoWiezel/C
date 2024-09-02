#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
 int code; // Código de reserva
 char start[3+1]; // Aeroporto de partida
 char end[3+1]; // Aeroporto de chegada
 char *desc; // Descrição do voo (string alojada dinamicamente)
} Flight; 

char *break_flight(char *text, int *code, char *start, char *end)
{
    char *text_copy = strdup(text);
    if(text_copy == NULL) return NULL;

    char *token = strtok(text_copy, "|");
    if(token == NULL) {free(text_copy); return NULL;}
    *code = atoi(token);

    token = strtok(NULL, "-");
    if(token == NULL) {free(text_copy); return NULL;}
    strcpy(start,token);

    token = strtok(NULL, "|");
    if(token == NULL) {free(text_copy); return NULL;}
    strcpy(end,token);

    token = strtok(NULL, "|");
    if(token == NULL) {free(text_copy); return NULL;}

    char *desc = strdup(token);
    if(desc == NULL) return NULL;
    free(text_copy);
    return desc;

}

Flight *create_flight(char *text)
{
    Flight *f = (Flight*) malloc(sizeof(*f));
    if(f == NULL) return NULL;

    f->desc = break_flight(text, &f->code, f->start, f->end);
    if(f->desc == NULL)  {free(f);return NULL;}

    return f;
}

void append_flight(Flight *flight, char *duration)
{
    char *aux = realloc(flight->desc, strlen(flight->desc)+strlen(duration)+strlen(" [")+strlen("]")+1);
    if(aux == NULL) return;

    flight->desc = aux;

    strcat(flight->desc, " [");
    strcat(flight->desc, duration);
    strcat(flight->desc, "]");
}