#include <stdio.h>

#define MAXL 100
#define MAXC 100

typedef struct {
    int pixels[MAXL][MAXC];
    int lines;  // Número de linhas usadas (0 a lines-1)
    int cols;   // Número de colunas usadas (0 a cols -1)
} Image;

void snipImage(Image *photo, int sl, int sc, int ln, int cn, Image *res) {
    if (sl < 0 || sc < 0 || sl + ln > photo->lines || sc + cn > photo->cols) {
        // O retângulo a recortar não está completamente contido em photo
        res->lines = 0;
        res->cols = 0;
        return;
    }

    res->lines = ln;
    res->cols = cn;

    for (int i = 0; i < ln; i++) {
        for (int j = 0; j < cn; j++) {
            res->pixels[i][j] = photo->pixels[sl + i][sc + j];
        }
    }
}

int main() {
    // Exemplo de utilização
    Image photo = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        3,  // lines
        3   // cols
    };

    Image result;
    snipImage(&photo, 0, 0, 2, 2, &result);

    // Exibindo o resultado
    printf("Imagem Recortada:\n");
    for (int i = 0; i < result.lines; i++) {
        for (int j = 0; j < result.cols; j++) {
            printf("%d ", result.pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}
