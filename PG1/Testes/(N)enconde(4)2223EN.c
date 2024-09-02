


// NAO PERCEBI
// Refiz de outra maneira, no outro codigo (Questao 4 2223 En.c)

#include <stdio.h>
#include <string.h>

void number_to_str(int n, char str_number[]) {

sprintf(str_number, "%d", n);

}

void encode (char dest[], const char src[]){
int contador = 1;
int tam = strlen(src);
int dest_index = 0;

    printf("total de letras: %d\n", strlen(src));

   for (int i = 0; i < tam - 1; i++) {
        if (src[i] == src[i + 1]) {
            contador++;
        } else {
            dest[dest_index++] = src[i];
            number_to_str(contador, &dest[dest_index]);
            dest_index += strlen(&dest[dest_index]);
            contador = 1;
        }
    }

    dest[dest_index++] = src[tam - 1];
    number_to_str(contador, &dest[dest_index]);
    dest_index += strlen(&dest[dest_index]);

    dest[dest_index] = '\0';
}

int main() {

    // Questão 3
    char string[1000];
    int x;

    printf("Digite um numero: ");
    scanf("%d", &x);

    number_to_str(x, string);

    printf("str_number = %s\n", string);

    // Questão 4
    char destino[1000];
    char str[1000];
    printf("Digite uma sequencia de letras qualquer: ");
    scanf("%s", str);
    encode(destino, str);

    printf("a string dest fica igual a %s", destino);

return 0;
}