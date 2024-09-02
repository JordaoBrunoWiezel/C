#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 15
#define AVAILABLE 0
#define RESERVED 1

typedef struct {
    int number; // número do assento
    int status; // AVAILABLE ou RESERVED
} Seat;

typedef struct {
    char name; // nome da seção
    Seat seats[MAX_ROWS][MAX_COLS]; // matriz de assentos
} TheaterSection;

typedef struct {
    TheaterSection sections[MAX_ROWS]; // seções do teatro
    int num_sections; // número de seções
} Theater;

int section_available_seats(TheaterSection *section) {

    int contador = 0;

    for(int i=0; i < section -> num_sections; i++){
        for(int p=0; p < MAX_ROWS; p++){
            for(int k=0; k < MAX_COLS; k++){
                if (section->sections[i].seats[p][k].status == 0){
                contador++;
            }
            }
        }
    
    }
return contador;   
}

/* b. [2] Utilizando a função anterior, implemente a função int reserve_seats(Theater *theater, int num_seats) 
que tenta reservar um determinado número de assentos consecutivos em qualquer seção do teatro. A função deve 
retornar o número total de assentos reservados ou -1 caso não seja possível realizar a reserva. */

int reserve_seats(Theater *theater, int num_seats) {
    
    int n_assentos = 0;


    for (int n = 0; n < theater->num_sections; n++) {
        if (section_available_seats(&(theater->sections[n])) == num_seats) {
            for (int a = 0; a < MAX_ROWS; a++) {
                for (int b = 0; b < MAX_COLS; b++) {
                    theater->sections[n].seats[a][b].status = 1;
                    n_assentos++;
                }
            }
            // Terminar o loop interno, pois já foram reservados os assentos desejados.
            break;
        }
    }
return n_assentos;
}