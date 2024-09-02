#include <stdio.h>
#include <math.h>

double nearpi(int n) {

    double soma = 0.0;
    double pi[n];

    for (int k = 1; k <= n; k++) {
        pi[k-1] = pow(-1, k + 1) / (2.0 * k - 1);
        soma += pi[k-1];
    }

    return 4 * soma;
}

int main () {

int x;
printf("Escolha um numero n de termos da serie: ");
scanf("%d", &x);

double resultado = nearpi(x);
printf("O resultado e: %.2f", resultado);


return 0;
}