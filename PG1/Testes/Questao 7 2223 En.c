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

bool park_check_place (const Parking *pk, int state, int *idx){
    for (int i= *idx; i < pk->total; i++){ 
        if(pk -> places[i].busy == state){
        *idx = i;
        return true;
        }
    }
return false;
}

int main() {
    Parking parking_lot;
    parking_lot.total = 5; // Supondo que existam 5 lugares

    parking_lot.places[0].busy = 1;
    parking_lot.places[1].busy = 0;
    parking_lot.places[2].busy = 0;
    parking_lot.places[3].busy = 1;
    parking_lot.places[4].busy = 0;

    int index = 0; // Índice inicial para a busca

    if (park_check_place(&parking_lot, 0, &index)) {
        printf("Encontrado lugar livre no indice %d.\n", index);
    } else {
        printf("Nao ha lugares livres.\n");
    }

    return 0;
}