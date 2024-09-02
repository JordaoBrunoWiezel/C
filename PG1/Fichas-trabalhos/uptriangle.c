#include <stdio.h>
#include <math.h>

int main() {
    // coordenadas dos 3 pontos (x,y)
    double x1, y1, x2, y2, x3, y3;
    // d1, d2, d3 são as distâncias dos 3 vértices
    double d1, d2, d3;
    // O perímetro do triângulo
    double P;

    // Leitura das coordenadas dos vértices
    printf("Digite as coordenadas dos três vértices: (x1 y1 x2 y2 x3 y3): ");
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);

    // Verifica se os pontos são distintos
    if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x1 && y3 == y1)) {
        printf("Existem pontos iguais.\n");
        
    } else {
		
        // Verifica se os pontos estão na mesma reta
        if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) {
            printf("Os pontos estão na mesma reta.\n");
            
        } else {
			
            // Calculo das distâncias entre os vértices
            d1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            d2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
            d3 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

            // Calculo do perímetro do triângulo
            P = d1 + d2 + d3;

            // Resultado
            printf("O perímetro do triângulo é: %.2lf\n", P);
        }
    }

    return 0;
}
