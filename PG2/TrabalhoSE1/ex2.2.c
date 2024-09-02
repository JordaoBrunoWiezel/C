#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <wchar.h>

int charLeadingOnes(char value)
{
    int i = CHAR_BIT - 1; // Para sabermos quantos bits tem um char
    int contador = 0;
    while (i >= 0)
    {
        if(!!(value & (1 << i)) == 1)
            contador++;
        else
            break;
    i--;
    }
    return (contador);
}

int utf8Length(const char a[], int i)
{
    char v = a[i];
    int resp;

   resp = charLeadingOnes(v);

    if(resp == 1)
        return (0);
    else if(resp == 0)
        return (1);
    else
        return (resp);
}
/*Escreva a função
int printSymbolCode( const char a[], int i );
destinada a apresentar, através de standard output, o símbolo iniciado na posição i, emitindo todos os
bytes que o formam, seguindo-se, entre parêntesis, os valores respetivos em hexadecimal a dois
algarismos. Retorna a quantidade de bytes do símbolo.*/

// Função para imprimir o código(valor em hex e nº de bytes) do símbolo em uma string UTF-8
int printSymbolCode( const char a[], int i )
{
    // Determina o número de bytes no caractere UTF-8 na posição i
    int bytes = utf8Length(a,i);
    
    // Se a funcao retornar 0, entao deve-se retornar 0
    if(bytes == 0) return 0;

    // Imprime o caractere UTF-8
    for(int z = i; z < i + bytes; z++) printf("%c", a[z]); // i+bytes por causa dos caracteres especiais ??
 
    printf("(");

    // Imprime o código em hexadecimal de cada byte do caractere UTF-8
    for(int j = 0; j < bytes; j++)
    {
        printf("%02x",(unsigned char)a[i+j]);

        // Se este não é o último byte, imprime um espaço
        if(j < bytes-1) printf(" ");
    }

    printf(")");

    // Retorna o número de bytes no caractere UTF-8
    return bytes;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf(" e possui %d bytes\n", printSymbolCode("olá", 0));
    printf(" e possui %d bytes\n", printSymbolCode("olá", 1));
    printf(" e possui %d bytes\n", printSymbolCode("olá", 2));
    printf(" e possui %d bytes\n", printSymbolCode("ç", 0));

return (0);
}