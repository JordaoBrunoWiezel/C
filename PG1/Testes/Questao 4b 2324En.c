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

// date_weekday
// Retorna o dia da semana (0 a 6, onde 0 é
// domingo ) da data d
int date_weekday(const date_t d);


void travel_apply_discount(agency_travel_t *ag, const date_t d, int disc){

    for(int i = 0; i <= ag -> num_travels; i++){

        int week = date_weekday(ag -> travels[i].departure_date);

        if(week >= 1 && week <= 4){
            ag -> travels[i].travel_cost *= (100-disc)/100
        }

    }
}