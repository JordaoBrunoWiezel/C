#include <stdio.h>
#include <stdbool.h>

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

int queue_check_places(Queue *q, int state, int idx){

    int contador = 0;

    for(int i = idx; i < q -> n_places; i++ ){
        if(q -> places[i].state == state){
            contador++;
        }
    }
return contador;
}

int queue_reserve_places (Queue *q, int n_places){

    for(int p = 0; p < q -> n_places; p++){
           
        if(q->places[p].state == FREE){
    
            if(queue_check_places(q, FREE, p) >= n_places){

                for(int k = p; k < p + n_places; k++){
                    q->places[k].state = BUSY;
                }
                return p;
            }
        }
    }
return -1;
}

bool theater_reserve_places (MovieTheater *m, int n_places, char *name, int *idxFirstPlace){

    for (int w = 0; w < m->n_queues; w++) {
        int indice = queue_reserve_places(&m->queues[w], n_places);

        if(indice != -1){
            *name = m->queues[indice].name;
            *idxFirstPlace = indice;
        return true;
        }
    }

return false;
}

// Esse int main foi o chatgpt
int main() {
    MovieTheater theater;

    // Numero maximo de lugares na fila(0)
    theater.n_queues = 3;

    // Fila A
    theater.queues[0].name = 'A';
    theater.queues[0].n_places = 5;
    for (int i = 0; i < theater.queues[0].n_places; i++) {
        theater.queues[0].places[i].state = FREE;
    }

    // Fila B
    theater.queues[1].name = 'B';
    theater.queues[1].n_places = 4;
    for (int i = 0; i < theater.queues[1].n_places; i++) {
        theater.queues[1].places[i].state = BUSY;
    }

    // Fila C
    theater.queues[2].name = 'C';
    theater.queues[2].n_places = 6;
    for (int i = 0; i < theater.queues[2].n_places; i++) {
        theater.queues[2].places[i].state = FREE;
    }

    printf("Estado inicial do cinema:\n");
    for (int i = 0; i < theater.n_queues; i++) {
        printf("Fila %c: ", theater.queues[i].name);
        for (int j = 0; j < theater.queues[i].n_places; j++) {
            printf("%d ", theater.queues[i].places[j].state);
        }
        printf("\n");
    }
    printf("\n");

    // Tenta reservar 3 lugares consecutivos em alguma fila
    char reserved_name;
    int reserved_idx;
    bool reservation_result = theater_reserve_places(&theater, 3, &reserved_name, &reserved_idx);

    if (reservation_result) {
        printf("Reserva bem-sucedida. Nome da fila: %c, Indice inicial da reserva: %d\n", reserved_name, reserved_idx);
    } else {
        printf("Não foi possível realizar a reserva.\n");
    }

    printf("\nEstado final do cinema:\n");
    for (int i = 0; i < theater.n_queues; i++) {
        printf("Fila %c: ", theater.queues[i].name);
        for (int j = 0; j < theater.queues[i].n_places; j++) {
            printf("%d ", theater.queues[i].places[j].state);
        }
        printf("\n");
    }

    return 0;
}
