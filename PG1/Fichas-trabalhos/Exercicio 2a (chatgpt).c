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

// a. [1] Implemente a função int section_available_seats(TheaterSection *section) que retorna o 
// número de assentos disponíveis em uma seção do teatro.
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