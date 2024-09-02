#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define MAX_LINE 20

typedef struct{
 int number; // Número de identificação
 char *name; // Nome (string alojada dinamicamente)
 char *function; // Cargo desempenhado (string alojada dinamicamente)
} Member; 

typedef struct{
 int count; // Quantidade de ponteiros alojados e preenchidos no array
 Member **array; // Array de ponteiros, alojado dinamicamente
} Staff; 

int lineParse(char *text, int *number, char *name, char *job)
{
    char *text_copy = strdup(text);
    if(text_copy == NULL) return 0;

    char *token = strtok(text_copy, ";");
    if(token == NULL) {free(text_copy); return 0;}
    *number = atoi(token);

    token = strtok(NULL, ";");
    if(token == NULL) {free(text_copy); return 0;}
    strcpy(name, token);

    token = strtok(NULL, ";");
    if(token == NULL) {free(text_copy); return 0;}
    strcpy(job, token);

    free(text_copy);
    return 1;
}

Member *memberCreate(char *text)
{
    /*Usar malloc(sizeof(Member)) ou malloc(sizeof(*m)) aloca memória suficiente para armazenar uma estrutura Member, 
    que inclui todos os seus campos (inteiro number e ponteiros name e function).*/
    Member *m = (Member*) malloc(sizeof(*m));
    if(m == NULL) return NULL;

    char    temp_name[MAX_LINE];
    char    temp_function[MAX_LINE];

    if(lineParse(text, &m->number, temp_name, temp_function) == 0)
    {free(m); return NULL;}

    /*Usar malloc(strlen(temp_name) + 1) aloca memória suficiente para a string temp_name e o terminador nulo.*/
    m->name = (char*) malloc(strlen(temp_name)+1);
    if(m->name == NULL) {free(m); return NULL;}
    strcpy(m->name, temp_name);

    m->function = (char*) malloc(strlen(temp_function)+1);
    if(m->function == NULL) {free(m); free(m->name); return NULL;}
    strcpy(m->function, temp_function);

    return m;
}

/* que adiciona ao vetor staff uma posição com o ponteiro para o elemento indicado por member. */
void staffAdd(Staff *staff, Member *member)
{
    Member **aux = realloc(staff->array, strlen(staff->count+1)*sizeof(Member*));
    if(aux == NULL) return;

    staff->array = aux;
    
    staff->array[staff->count] = member;
    staff->count++;

}