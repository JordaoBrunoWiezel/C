#include <stdio.h>
#include <stdbool.h>

#define MAX_PARK 300

typedef struct {
 int hour;
 int minute;
} Time;

typedef struct {
 int busy; // 0 – livre; 1 - ocupado
 Time hour_in; // tempo de entrada
} Park;

typedef struct {
 Park places[MAX_PARK]; // lugares do parque
 int total; // total dos ocupados
} Parking;



bool park_check_place(const Parking *pk, int state, int *idx) {
    
    for (int i = *idx; i < MAX_PARK; i++) {
        if (pk->places[i].busy == state) {
            *idx = i; // Atualiza o índice
            return true;
        }
    }
    return false;
}

int main() {
    Parking parking_lot;
    parking_lot.total = 0;

    int startingIndex = 0; // Índice inicial para a busca

    if (park_check_place(&parking_lot, 0, &startingIndex)) {
        printf("Encontrado lugar livre no indice %d.\n", startingIndex);
    } else {
        printf("Não há lugares livres.\n");
    }

    return 0;
}