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

typedef struct listFlight{
 Flight *flight;
 struct listFlight *next;
} ListFlight; 

/* destinada a encontrar e retirar de uma lista, cujo ponteiro cabeça é indicado por headAddr, um
elemento identificado pelo código de reserva code.
Em caso de sucesso, retorna o endereço do elemento retirado da lista; deve deixar este elemento
ativo, para utilização, e eliminar o nó de lista onde se encontrava o seu acesso. Se o código
pesquisado não existir, não modifica a lista e retorna NULL
*/

Flight *listRemove(ListFlight **headAddr, int code)
{
    ListFlight *current = *headAddr;
    ListFlight *previous = NULL;

    // Percorrer a lista
    while (current != NULL) {
        // Verificar se encontramos o código de reserva
        if (current->flight->code == code) {
            // Ajustar os ponteiros para remover o nó da lista
            if (previous == NULL) {
                // Remover o primeiro nó (cabeça da lista)
                *headAddr = current->next;
            } else {
                // Remover um nó intermediário ou final
                previous->next = current->next;
            }
            // Salvar o endereço do elemento Flight a ser removido
            Flight *removedFlight = current->flight;
            // Liberar o nó da lista
            free(current);
            // Retornar o endereço do elemento Flight removido
            return removedFlight;
        }
        // Atualizar ponteiros
        previous = current;
        current = current->next;
    }

    // Se não encontrar o código de reserva, retornar NULL
    return NULL;
}

// ou

Flight *listRemove(ListFlight **headAddr, int code) {
    ListFlight *current = *headAddr;
    ListFlight *previous = NULL;

    // Traverse the list to find the node with the given code
    while (current != NULL && current->flight->code != code) {
        previous = current;
        current = current->next;
    }

    // If the code was not found, return NULL
    if (current == NULL) {
        return NULL;
    }

    // Remove the node from the list
    if (previous == NULL) {
        // The node to be removed is the head
        *headAddr = current->next;
    } else {
        // The node to be removed is in the middle or at the end
        previous->next = current->next;
    }

    // Retrieve the flight data and free the list node
    Flight *removedFlight = current->flight;
    free(current);

    // Return the removed flight
    return removedFlight;
}