#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*Pretende-se produzir mnemónicas de nomes contidos em strings, com várias palavras separadas por
um ou vários espaços. A mnemónica contém a primeira palavra, exatamente como está escrita,
seguida de um espaço e de uma sigla formada pelas iniciais das palavras seguintes, em maiúsculas.
Exemplos: "Luis Vaz de Camoes "  mnemónica: "Luis VDC";
 " RIta REIS dos SANtos"  mnemónica: "RIta RDS".
Escreva a função
void mnemonic( char *str );
que modifica a string indicada por str, depositando, no mesmo espaço, a mnemónica resultante
do seu conteúdo inicial.
Propõe-se que use a primitiva «int toupper(int c);» declarada no header file ctype.h. 
*/

void mnemonic( char *str )
{
    char *token = strtok(str, " "); // fica Jordao\0Bruno Wiezel
    if(token == NULL) return; //  isso significa que a string original não contém nenhum token válido (ela estava vazia ou consistia apenas em delimitadores).

    int index = strlen(token); // no caso vai ser 6 (jordao)
    strcpy(str, token); //isso serve para tirar os espaços da str original

    str[index++] = ' ';

    while((token = strtok(NULL, " ")) != NULL)
        str[index++] = toupper(*token);

    str[index] = '\0';

}

int main() {
    char str[] = "   Jordao Bruno Wiezel "; // Array mutável

    printf("Before:%s\n", str);
    mnemonic(str);
    printf("After:%s\n", str);

    return 0;
}