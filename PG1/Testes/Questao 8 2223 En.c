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

bool park_check_place (const Parking *pk, int state, int *idx){
    for (int i= *idx; i < pk->total; i++){ 
        if(pk -> places[i].busy == state){
        *idx = i;
        return true;
        }
    }
return false;
}

int park_in (Parking *pk, Time t_in){

    int idx = 0;

    if(park_check_place (pk, 0, &idx)){
        pk -> places[idx].busy = 1;
        pk -> places[idx].hour_in = t_in;
        pk -> total++;
        return idx;
    } else {
        return -1;
    }
}