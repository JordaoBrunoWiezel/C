#include <stdio.h>

typedef struct{
 int number; // Número de identificação
 char *name; // Nome (string alojada dinamicamente)
 char *function; // Cargo desempenhado (string alojada dinamicamente)
} Member; 

typedef struct listStaff{
 struct listStaff *next; // ligação na lista
 Member *ref; // referência: ponteiro para o elemento de dados
} ListStaff; 

void listInvert(ListStaff **headAddr)
{
    ListStaff *current = *headAddr;
    ListStaff *Previos = NULL;
    ListStaff *next = NULL;

    while(current != NULL)
    {
        next = current->next;       //guarda o proximo nó
        current->next = Previos;    // Inverte a ligação do nó atual
        Previos = current;          // Move o ponteiro prev pra o nó atual      
        current = next;             // Avança para o proximo nó
    }

    *headAddr = Previos; //// Atualiza a cabeça da lista para o novo primeiro nó
}