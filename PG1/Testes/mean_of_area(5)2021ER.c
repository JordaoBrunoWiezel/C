#include <stdio.h>
#include <stdbool.h>

#define LINES 2
#define COLS 4

typedef int Image[LINES][COLS];

bool mean_of_area(Image img, int l, int c, int lines, int cols, double *pmean) {
    
    if(l < 0 || c < 0 || l + lines > LINES || c + cols > COLS ){   
        // Área não está completamente contida na imagem
    return false;
    }

    int sum = 0;
    int contador = 0;

    for(int i = l; i < l + lines; i++){
        for(int j = c; j < c + cols; j++){
            sum += img[i][j];
            contador ++;
        }
    }

    *pmean = (double)sum/contador;

return true;
}

int main() {
    Image img = {
        {10, 15, 18, 16},
        {30, 35, 35, 38}
    };

    int l = 0, c = 1, lines = 2, cols = 2;  // Exemplo de área retangular
    double mean;

    if (mean_of_area(img, l, c, lines, cols, &mean)) {
        printf("Média da área retangular: %lf\n", mean);
    } else {
        printf("Área não completamente contida na imagem.\n");
    }

    return 0;
}
