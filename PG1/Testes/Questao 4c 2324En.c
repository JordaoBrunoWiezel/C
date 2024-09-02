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


// Função para obter o índice da viagem mais barata para um destino em um intervalo de datas
int travel_cheaper(agency_travel_t *ag, const date_t d1, const date_t d2, const char destination[]) {
    int cheapest_index = -1;
    float cheapest_cost = -1;

    for (int i = 0; i < ag->num_travels; i++) {
        // Verifica se a viagem é para o destino desejado
        if (strcmp(ag->travels[i].arrival_city, destination) == 0) {
            // Verifica se a data de partida está dentro do intervalo [d1, d2]
            if (date_cmp(ag->travels[i].departure_date, d1) >= 0 && date_cmp(ag->travels[i].departure_date, d2) <= 0) {
                // Verifica se é a viagem mais barata até agora
                if (cheapest_index == -1 || ag->travels[i].travel_cost < cheapest_cost) {
                    cheapest_index = i;
                    cheapest_cost = ag->travels[i].travel_cost;
                }
            }
        }
    }

    return cheapest_index;
}