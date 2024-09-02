
// SEMPRE ESTA DANDO 0

#include <stdio.h>

#define MAX 80
#define FREE 0
#define BUSY 1

typedef struct {
 int number; // nº do lugar
 int state; // FREE ou BUSY
} Place;

typedef struct {
 char name; // nome da fila
 Place places[MAX]; // Máximo de lugares por fila
 int n_places; // número lugares da fila
} Queue;

typedef struct {
 Queue queues[MAX]; // Máximo de filas
 int n_queues; // número de filas
} MovieTheater;

int queue_check_places(Queue *q, int state, int idx) {

    int consecutive_count = 0;
    
    for (int i = idx; i < q->n_places; i++) {
        if (q->places[i].state == state) {
            consecutive_count++;
        } else {
            break;
        }
    }
    return consecutive_count;
}


int main(){

    Queue Lot;

    Lot.n_places = 50; // // Defina o número desejado de lugares para o exemplo

    int starting_idx = 0;

    int numero = queue_check_places(&Lot, FREE ,starting_idx);

    printf("Numero de lugares consecutivos com estado 0(FREE): %d", numero);

return 0;
}