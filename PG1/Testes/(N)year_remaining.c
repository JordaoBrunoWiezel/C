

// NÃO ESTA CERTO

#include <stdio.h>
#include <stdbool.h>

bool is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
     return false;
}

int days_in_month(int month, int year) {
    
    int dia_no_mes;
    if (month==2){
        if (is_leap_year(year) == true) {
            dia_no_mes = 29;
        } else {
            dia_no_mes = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11){
        dia_no_mes = 30;
    } else {
        dia_no_mes = 31;
    }    
return dia_no_mes;
}

void year_remaining_days (int day, int month, int year){

for (int m = month; m <= 12; m++) {

    switch (m) {
        case 1: printf("Janeiro %d\n", year); break;
        case 2: printf("Fevereiro %d\n", year); break;
        case 3: printf("Marco %d\n", year); break;
        case 4: printf("Abril %d\n", year); break;
        case 5: printf("Maio %d\n", year); break;
        case 6: printf("Junho %d\n", year); break;
        case 7: printf("Julho %d\n", year); break;
        case 8: printf("Agosto %d\n", year); break;
        case 9: printf("Setembro %d\n", year); break;
        case 10: printf("Outubro %d\n", year); break;
        case 11: printf("Novembro %d\n", year); break;
        case 12: printf("Dezembro %d\n", year); break;
    }
        printf("   D   S   T   Q   Q   S   S\n");



   int dia_no_mes = days_in_month(month, year);

        // Calcula o dia da semana do primeiro dia do mês
        int firstDayOfMonth = (day + 6) % 7;

        for (int i = 0; i < firstDayOfMonth; i++) {
            printf("    ");
        }

        for (int d = 1; d <= dia_no_mes; d++) {
            printf("%4d", d);
            firstDayOfMonth = (firstDayOfMonth + 1) % 7;

            if (firstDayOfMonth == 0 || d == dia_no_mes) {
                printf("\n");
            }
        }
        printf("\n");

        // Atualiza o dia para o primeiro dia do próximo mês
        day = (day + dia_no_mes) % 7;
    }
}


int main(){

int dia, mes, ano;
printf("Diga um ano: ");
scanf("%d", &ano);

printf("Diga um mes: ");
scanf("%d", &mes);
    if (mes<1 || mes>12) {
        printf("Mes invalido!");
    return 0;       
    }

printf("Diga um dia: ");
scanf("%d", &dia);
    if(dia<1 || dia>31){
        printf("Dia invalido!");
    return 0;
    }

year_remaining_days(dia, mes, ano);

return 0;
}