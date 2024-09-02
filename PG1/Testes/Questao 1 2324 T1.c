#include <stdio.h>

void classify_straight_line(double x1, double y1, double x2, double y2) {
    if (x1 == x2 && y1 == y2) {
        printf("Nao existe reta\n");
    } else if (x1 == x2) {
        printf("Reta vertical\n");
    } else if (y1 == y2) {
        printf("Reta horizontal\n");
    } else {
        printf("Reta obliqua\n");
    }
}

int main() {
    double x1, y1, x2, y2;

    printf("Escolha dois pontos x1, y1, x2, y2: ");
    scanf("%lf, %lf, %lf, %lf", &x1, &y1, &x2, &y2);

    classify_straight_line(x1, y1, x2, y2);

    return 0;
}
