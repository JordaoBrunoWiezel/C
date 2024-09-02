
// Esta errado por causa da primeira função

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

int queue_check_places (Queue *q, int state, int idx){

    int consecutive_count = 0;

    for(int i = idx; i < q -> n_places; i++){
        if(q -> places[i].state == state){ 
            consecutive_count++;
        } else {
            break;
        }
    }
    return consecutive_count;
}

int queue_reserve_places(Queue *q, int n_places){

    // Sem ultrapassar o limite da fila. Por exemplo, se a fila tiver 10 lugares 
    // e você quiser reservar 3 lugares consecutivos (n_places), o loop começará no índice 0 e terminará no índice 7 (10 - 3).
    for (int i = 0; i <= q->n_places - n_places; i++) {
        if (queue_check_places(q, FREE, i) == n_places) {
            // Encontrou n_places lugares livres consecutivos, atualiza o estado
            // Se você quiser reservar 3 lugares consecutivos a partir do índice 5, o loop começará no índice 5 e terminará no índice 7
            for (int j = i; j < i + n_places; j++) {
                q->places[j].state = BUSY;
            }
            return i; // Retorna o índice inicial da reserva
        }
    }
    return -1; // Não foi possível realizar a reserva
}

int main() {
    Queue Lot;
    Lot.n_places = 10; // Defina o número desejado de lugares para o exemplo

    int n_places_to_reserve = 3;

    int starting_idx = queue_reserve_places(&Lot, n_places_to_reserve);

    if (starting_idx != -1) {
        printf("Reserva realizada com sucesso! Indice inicial: %d\n", starting_idx);
    } else {
        printf("Nao foi possivel realizar a reserva.\n");
    }

    return 0;
}
