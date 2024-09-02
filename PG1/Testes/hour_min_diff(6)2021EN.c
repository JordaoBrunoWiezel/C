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

 int hr_min_diff(Hour h1, Hour h2){

    int diff = (h2. hours- h1.hours)*60+(h2.minutes - h1 .minutes);
    return diff;

}

 int main() {
    // Exemplo de uso
    Hour start_time = {9, 30};
    Hour end_time = {14, 45};

    int difference = hr_min_diff(start_time, end_time);

    printf("Diferença em minutos: %d\n", difference);

    return 0;
}