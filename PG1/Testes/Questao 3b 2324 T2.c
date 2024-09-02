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


int travel_cheaper(agency_travel_t *ag, const date_t d1, const date_t d2, const char destination[]){

    int indice = -1, barata = -1;

    for(int i = 0; i < ag->num_travels; i++){

        if(strcmp(ag->num_travels[i].arrival_city, destination) == 0){
            if(date_cmp(ag->num_travels[i].departure_date, d1) > 0 && date_cmp(ag->num_travels[i].departure_date, d2) < 0){
                if(ag->num_travels[i].travel_cost < barata){
                    indice = i;
                    num_travels[i].travel_cost = barata;
                }
            }
        }
    }
return barata;
}