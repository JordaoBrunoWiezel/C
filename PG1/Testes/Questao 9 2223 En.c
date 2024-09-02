#include <stdio.h>
#include <stdbool.h>

#define MAX_PARK 300

typedef struct {
 int hour;
 int minute;
} Time;

typedef struct {
 int busy; // 0 – livre; 1 - ocupado
 Time hour_in; // tempo de entrada
} Park;

typedef struct {
 Park places[MAX_PARK]; // lugares do parque
 int total; // total dos ocupados
} Parking;


double park_calc_cost (const Time *t_in, const Time *t_out, int t_fraction, double v_fraction){

    int intervalo = (t_out->hour*60 + t_out->minute) - (t_in->hour*60 + t_in->minute);

    printf("%d minutos\n", intervalo);

    double fracao = intervalo/t_fraction;
        if(intervalo % t_fraction != 0.0){
            fracao += 1;
        }

    double valor = fracao*v_fraction;

return valor;
}

int main (){

Time t_in ={20,0}, t_out ={21,1}; // entra e sai do estacionamento
int t_fraction = 15; // cada fração é de 00:15
double v_fraction = 0.5; // valor de cada fração é de 50 cêntimos


double v = park_calc_cost(&t_in, &t_out, t_fraction, v_fraction);

 printf("Entrou (%02d:%02d), Saiu (%02d:%02d). Cada fracao(%d) e (%.2lf) euros. Total a pagar %.2lf\n", t_in.hour, t_in.minute, t_out.hour, t_out.minute, t_fraction, v_fraction, v);

}