#include <stdio.h>
#include <string.h>
#include <ctype.h>

int remove_case_letter(const char src[], char dst[], char letter) {
    int contador = 0;  // Variável para contar o número de caracteres eliminados
    int tam = strlen(src);
    int tamExc = 0;  // Variável para controlar o tamanho do array de caracteres excluídos

    printf("Tamanho da string: %d\n", tam);

    // Loop para remover caracteres iguais a 'letter' e contar as remoções, sem primeiro usar tolower e dps fazer o procedimento
    // Mantem as letras maiuscula e minusculas / forma mais rapida
    for (int d = 0; d < tam; d++) {
        if (tolower(src[d]) == tolower(letter)) {
            contador++;
        } else {
            dst[tamExc] = src[d];
            tamExc++;
        }
    }

   /*
    // Loop para converter os caracteres para minúsculas
    for (int i = 0; i < tam; i++) {
        dst[i] = tolower(src[i]);
    }
    dst[tam] = '\0';  // Termina a string convertida

    printf("frase em minusculo: %s\n", dst);

    // Loop para remover caracteres iguais a 'letter' e contar as remoções
    for (int d = 0; d < tam; d++) {
        if (dst[d] == letter) {
            contador++;
        } else {
            dst[tamExc] = dst[d];
            tamExc++;
        }
    }
    */

    dst[tamExc] = '\0';  // Termina a string resultante

return contador;  // Retorna o número de caracteres eliminados
}



int main(){

char src[50] = ("Demenchuk Wiezel.");
char dst[50];
char letter = 'e';

int contador = remove_case_letter(src, dst, letter);

printf("Nova frase: %s\n", dst);
printf("Vezes de '%c' retiradas: %d\n", letter, contador);


return 0;
}