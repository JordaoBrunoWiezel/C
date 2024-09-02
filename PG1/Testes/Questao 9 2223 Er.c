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

int queue_check_places(Queue *q, int state, int idx){

    int contador = 0;

    for(int i = idx; i < q -> n_places; i++ ){
        printf("Antes: Lugar %d: Estado %d\n", i, q->places[i].state);
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
                    printf("Depois: Lugar %d: Estado %d\n", k, q->places[k].state);
                }
                return p;
            }
        }
    }
return -1;
}

int main() {
    MovieTheater theater;

    // Numero maximo de lugares na fila(0)
    theater.queues[0].n_places = 3;

    // Inicialize a estrutura MovieTheater, Queue e Place conforme necessário
    // Exemplo de inicialização da fila e de alguns lugares
    theater.queues[0].places[0].state = FREE;
    theater.queues[0].places[1].state = FREE;
    theater.queues[0].places[2].state = FREE;

    // Tente reservar 2 lugares consecutivos na fila 0
    int result = queue_reserve_places(&theater.queues[0], 2);

    if (result != -1) {
        printf("Reserva bem-sucedida. Indice inicial da reserva: %d\n", result);
    } else {
        printf("Não foi possível realizar a reserva.\n");
    }

    return 0;
}