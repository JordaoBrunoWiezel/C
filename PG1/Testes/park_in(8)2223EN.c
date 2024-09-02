#include <stdio.h>
#include <stdbool.h>

#define MAX_PARK 300

typedef struct {
    int hour;
    int minute;
} Time;

typedef struct {
    int busy;       // 0 – livre; 1 - ocupado
    Time hour_in;   // tempo de entrada
} Park;

typedef struct {
    Park places[MAX_PARK];  // lugares do parque
    int total;              // total dos ocupados
} Parking;


bool park_check_place(const Parking *pk, int state, int *idx) {
    for (int i = *idx; i < MAX_PARK; i++) {
        if (pk->places[i].busy == state) {
            *idx = i;  // Atualiza o índice
            return true;
        }
    }
    return false;
}

int park_in(Parking *pk, Time t_in) {

    int startingIndex = 0;  // Índice inicial para a busca

    if (pk-> total < MAX_PARK && park_check_place(pk, 0, &startingIndex)) {
        // Encontrou um lugar livre
        pk->places[startingIndex].busy = 1;   // Marca o lugar como ocupado
        pk->places[startingIndex].hour_in = t_in;  // Registra o tempo de entrada
        pk->total++;  // Incrementa o total de ocupados
        return startingIndex;  // Retorna o índice do lugar ocupado
    } else {
        // Não há lugares livres ou o estacionamento está cheio
        return -1;
    }
}

int main() {
    Parking parking_lot;
    parking_lot.total = 0;

    Time entrada = {10, 30};  // Exemplo de tempo de entrada

    int resultado = park_in(&parking_lot, entrada);

    if (resultado != -1) {
        printf("Carro estacionado no indice %d.\n", resultado);
    } else {
        printf("Estacionamento cheio. Nao foi possivel estacionar.\n");
    }

    return 0;
}

