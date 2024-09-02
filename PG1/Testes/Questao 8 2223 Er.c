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

    for(int i = idx; i < q->n_places; i++ ){
        printf("Lugar %d: Estado %d\n", i, q->places[i].state);
        if(q -> places[i].state == state){
            contador++;
        }
    }
return contador;
}

int main() {
    MovieTheater theater;

    // Numero maximo de lugares na fila(0)
    theater.queues[0].n_places = 3;

    // Inicialize a estrutura MovieTheater, Queue e Place conforme necessário
    // Exemplo de inicialização da fila e de alguns lugares
    theater.queues[0].places[0].state = BUSY;
    theater.queues[0].places[1].state = BUSY;
    theater.queues[0].places[2].state = BUSY;

    // Verifique se a função está funcionando corretamente
    int result = queue_check_places(&theater.queues[0], BUSY, 0);
    printf("Numero de lugares consecutivos ocupados: %d\n", result);

    return 0;
}