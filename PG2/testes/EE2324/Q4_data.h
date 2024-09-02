#ifndef __DATA_H__
#define __DATA_H__

#include <types.h>

Data* dCreate(void);               // Cria e retorna um novo ponteiro para Data
void dAdd(Data* d, const char* name, int num); // Adiciona um elemento à estrutura Data existente
void dSort(Data* d);               // Ordena a estrutura Data existente
void dPrint(const Data* d);        // Imprime a estrutura Data existente
void dDelete(Data* d);             // Libera a memória da estrutura Data existente

#endif