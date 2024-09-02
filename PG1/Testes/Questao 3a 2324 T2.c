#include <stdio.h>
#include <string.h>

#define MAX_NAME 80 // máximo nome
#define MAX_T 1000 // máximo de viagens

// Estrutura que representa a viagem
typedef struct {
char arrival_city[MAX_NAME];
float travel_cost;
date_t departure_date;
} travel_t;

// Estrutura que representa a agência de viagens
typedef struct {
travel_t travels[MAX_T];
int num_travels; // nº viagens disponíveis
} agency_travel_t;

// Estrutura que representa uma data
typedef struct {
int day;
int month;
int year;
} date_t;

// funções já implementadas:
// date_cmp
// Compara duas datas. Retorna um valor
// negativo, zero ou positivo, consoante d1
// seja menor, igual ou maior do que d2
int date_cmp(const date_t d1, const date_t d2);


bool travel_add(agency_travel_t *ag, const travel_t *tr){

    if(ag->num_travels >= MAX_T){
        return false;
    }

    for(int i= 0; i < ag -> num_travels; i++){  
        if((strcmp(ag->travels[i].arrival_city, tr->arrival_city)==0) || (date_cmp(ag->num_travels[i].departure_date, tr->departure_date) == 0)){
            return false;
        }
    }
    ag->travels[ag->num_travels] = *tr; // Adicione a nova viagem
    ag->num_travels++;

return true;
}