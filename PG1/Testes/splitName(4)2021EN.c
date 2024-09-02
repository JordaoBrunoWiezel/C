#include <stdio.h>

void splitName(const char name[], char lastName[], char restOfName[]) {

    int tamLN = 0;
    int tamRON = 0;
    int indice = 0;
    int contador = 0;

    while(name[contador] != '\0'){
        contador++;
    }

    for (int i = contador - 1; i >= 0; i--) {
        if (name[i] == ' ') {
            indice = i;
            break;
        }
    }

    for (int j = indice + 1; j <= contador; j++) {
        lastName[tamLN] = name[j];
        tamLN++;
    }

    for (int k = 0; k < indice; k++) {
        restOfName[tamRON] = name[k];
        tamRON++;
    }

    lastName[tamLN] = '\0';
    restOfName[tamRON] = '\0';
}

int main() {
    char name[] = "Jordao Bruno Wiezel";
    char lastName[50];
    char restOfName[50];

    splitName(name, lastName, restOfName);

    printf("Sobrenome: %s\nNome: %s", lastName, restOfName);

    return 0;
}
