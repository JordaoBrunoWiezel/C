#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 80 // máximo nome
#define MAX_EVENTS 1000 // máximo de eventos

// Estrutura que representa um evento
typedef struct {
  char event_name[MAX_NAME];
  float ticket_price;
  date_t event_date;
} event_t;

// Estrutura que representa a empresa de eventos
typedef struct {
  event_t events[MAX_EVENTS];
  int num_events; // número de eventos disponíveis
} event_company_t;

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

/*4.a) [2] Implemente a função bool add_event(event_company_t *company, const event_t *ev) que adiciona o evento ev
 à empresa de eventos company. Em caso de sucesso, a função retorna true. Se a empresa estiver cheia ou se já existir 
 um evento com o mesmo nome e na mesma data, o evento não é adicionado, e a função retorna false.*/

bool add_event(event_company_t *company, const event_t *ev){

    if(company->num_envents > MAX_EVENTS){
        return false;
    }


    for(int i= 0; i < company->num_events; i++){
         if(strcmp(company->eventes[i].event_name[], ev->event_name[]) == 0){        
            return false;
        }
        if(date_cmp(company->events[i].event_date, ev->event_date) == 0){
            return false;
        }
    }
company->events[company->events] = *ev;
company->num_events++;
}

/*b) [3] Implemente a função void apply_discount(event_company_t *company, const date_t d, float disc) 
que aplica um desconto disc, um valor em percentagem de 0 a 100, aos eventos registrados na empresa company 
para os quais haja eventos com uma data d em que o dia de realização esteja entre segunda-feira e quinta-feira.*/

void apply_discount(event_company_t *company, const date_t d, float disc){

        for(int i = 0; i < company->num_events; i++){
            if (date_weekday(company->events[i].event_date) >= 1 && date_weekday(company->events[i].event_date) <= 4) {
                company->events[i].ticket_price *= (100-disc)/100;
            }
        }


}

/*c) [3] Implemente a função int cheapest_event(event_company_t *company, const date_t d1, const date_t d2, const char event_name[]) 
que retorna o índice do evento mais barato para o nome de evento indicado em event_name, dentro do intervalo de datas de d1 a d2. 
Se não houver nenhum evento disponível, a função retorna -1. Para comparar datas, utilize a função date_cmp já implementada.*/

int cheapest_event(event_company_t *company, const date_t d1, const date_t d2, const char event_name[]) {

    int min_price = -1;
    int cheapest_index = -1;


       for(int i = 0; i < company->num_events; i++){
            if(date_cmp(company->events[i].event_date,d1) >= 0 && date_cmp(company->events[i].event_name,d2) <= 0){
                if(strcmp(company->events[i].event_name, event_name) == 0) {
                    if (cheapest_index == -1 || company->events[i].ticket_price < min_price) {
                        min_price = company->events[i].ticket_price;
                        cheapest_index = i;
                    }
                }
            }


        }
return cheapest_index;
}