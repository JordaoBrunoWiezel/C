#include <stdio.h>

int main(){

int ano, mes, dia, dias_no_mes;

printf("Qual o ano? ");
scanf("%d", &ano);

//verifica o ano
if(ano<0){
    printf("O que introduziu esta incorreto, digite um ano valido\n ");
return 1;
}
if(ano-(int)ano!=0){
    printf("O que introduziu esta incorreto, digite um ano valido\n ");
return 2;
}

else{
printf("Qual o mes? ");
scanf("%d", &mes);
}

//verifica o mes
if (mes < 1 || mes > 12 || (mes-(int)mes!=0)){
    printf("O que introduziu esta incorreto, digite um mes valido");
return 3;
}

printf("Qual o dia? ");
scanf("%d",  &dia);

//Verifica o dia
if(dia < 0 || dia > 6){
    printf("O que introduziu esta incorreto, digite um dia valido");
return 4;
}


for (int m = mes; m <= 12; m++) {

    switch (m) {
        case 1: printf("Janeiro %d\n", ano); break;
        case 2: printf("Fevereiro %d\n", ano); break;
        case 3: printf("Marco %d\n", ano); break;
        case 4: printf("Abril %d\n", ano); break;
        case 5: printf("Maio %d\n", ano); break;
        case 6: printf("Junho %d\n", ano); break;
        case 7: printf("Julho %d\n", ano); break;
        case 8: printf("Agosto %d\n", ano); break;
        case 9: printf("Setembro %d\n", ano); break;
        case 10: printf("Outubro %d\n", ano); break;
        case 11: printf("Novembro %d\n", ano); break;
        case 12: printf("Dezembro %d\n", ano); break;
    }
        printf("   D   S   T   Q   Q   S   S\n");

    // Espaços em branco para o dia da semana do dia 1
    for(int ds=0; ds < dia; ds++){
        printf("    ");
    }

    // Definir o numero de dias no mes
    if (m==2) {
        //Verificar se fevereiro é um ano bissexto
        if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        dias_no_mes=29;
        } else {
        dias_no_mes = 28;
        }
        //Verificar o numero de dias que cada mes tem
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        dias_no_mes = 30;
    } else {
        dias_no_mes = 31;
    }

    // Define os dias do mes
    for (int d = 1; d <= dias_no_mes; d++) {
        printf("%4d", d);
        dia = (dia + 1) % 7;
        if (dia == 0){
            printf("\n");
        }       
    }
    printf("\n");
}
return 0;
}