#include <stdio.h>
#include <math.h>

double d(double xA, double yA, double xB, double yB) {
    return sqrt(pow(xB - xA, 2) + pow(yB - yA, 2));
}

int main() {
    // Declaração das variáveis para as coordenadas dos pontos
    int x1, x2, x3, y1, y2, y3;

    // Solicita ao usuário que insira o valor das 3 coordenadas (x, y)
    printf("Escreva o valor das 3 coordenadas (x, y): ");
    scanf("%d,%d %d,%d %d,%d", &x1, &y1, &x2, &y2, &x3, &y3);

    // Verifica se os pontos são distintos
    if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3)) {
        printf("Existem coordenadas iguais, escreva novamente!\n");
    } else {
        // Verifica se os pontos estão na mesma reta
        if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) {
            printf("Os pontos estão na mesma reta.\n");
        } else {
            // Calcula as distâncias entre os pontos 
            double d1 = d(x1,y1, x2,y2);
            double d2= d(x3,y3, x2,y2);
            double d3 = d(x1, y1, x2,y2);

            // Calcula o perímetro do triângulo
            double p = d1 + d2 + d3;

            printf("O perimetro do triangulo e: %.2lf", p);
        }
    }

    return 0;
}