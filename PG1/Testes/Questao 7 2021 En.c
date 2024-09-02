#include <stdio.h>

#define MAX_N 80 //Máximo de caracteres do nome
#define MAX_T 1000 //Máximo de tarefas

typedef struct {
 int day, month, year;
} Date;

typedef struct {
 int hours, minutes;
} Hour;

typedef struct {
 Date date; // Data da tarefa
 Hour h_in; // Hora de entrada
 Hour h_out; // Hora de saída
} Task;

typedef struct {
 int id; // número do trabalhador
 char name[MAX_N]; // nome do trabalhador
 Task tasks[MAX_T]; // tarefas efetuadas
 int nTasks; // total de tarefas
} Worker;

int hr_min_diff(Hour h1, Hour h2) {
    
    int min = (h1.hours*60+h1.minutes)-(h2.hours*60+h2.minutes);
    return min;
}

 int countMinutesOfWorker(Worker *w, Date dtInit, Date dtFinal){

    int minW = 0;

    for(int i=0; i < w-> n_tasks; i++){
        if (cmpData(w->tasks[i].date, dtInit) >= 0 && cmpData(w->tasks[i].date, dtFinal) <= 0) {
           minW += hor_min_diff(w->tasks[i].h_out, w->tasks[i].h_in);
        }
    }
return minW;

}

int main(){
    
}