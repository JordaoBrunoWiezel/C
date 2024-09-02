#include <stdio.h>
#include <math.h>

int main(){

double p;
printf("Indique a diagonal do ecrã em polegadas: ");
scanf("%lf", &p);

// converte a diagonal de polegadas (p) apra centimetros (d)
double d = p*2.54;

// d^2 = (16*x)^2 + (9+x)^2 <=> d^2 = 337x^2 <=> x = sqrt (d^2/337)
double x = sqrt(d*d /337);
    
double a = 9*x;
double b = 16*x;

printf("Altura do ecra: %.1f cm\n", a);
printf("Comprimento do ecra: %.1f cm\n", b);

return 0;
}