#include <stdio.h>
#include <limits.h>

int charLeadingOnes( char value )
{
   int count = 0;
   int size = sizeof(value)*CHAR_BIT; // Para sabermos quantos bits tem um char (sizeof retorna o nº de bytes, 1 char tem 1 byte x 8)
   for(int i=size-1;i>=0;i--) //um ciclo que percorre a string desde o bit mais significativo ao menos significativo
   {
    if(!!(value & (1<<i)) == 1)// se o bit de posiçao i, após a operação AND com o numero 1 der 1 então o contador incrementa
    {
        count ++;
    }else{
        break; //se for 0 o ciclo termina
    }
   }
   return count; // por fim retornamos o numero de '1's consecutivos
}

/* .Escreva uma função para identificar a quantidade de bytes da representação de um símbolo em UTF-8:
int utf8Length( const char a[], int i );
A função recebe, no parâmetro a, um array cujo elemento de índice i é o primeiro byte de um símbolo.
Retorna a quantidade total de bytes do símbolo; pode ser: 1, no caso de ASCII básico, ou uma quantidade
superior, até quatro, no caso de símbolos compostos.
Na utilização da função utf8Length, deve ser sempre passada a posição inicial de um símbolo; no
entanto, se for indicada uma posição subsequente de um símbolo composto, pode retornar 0. */

int utf8Length( const char a[], int i) // Essa funcao retorna a quantidade de bytes de um simbolo
{
   int firstbyte = a[i]; // cria uma variavel, com o indice do array
   int charleadingones = charLeadingOnes(firstbyte); // chama a outra funcao, ve se o array no indice i é 1 ou 0

   if(charleadingones == 0)
   {
    return 1;   // se o primeiro byte é 0, significa que está na primeira linha da tabela UTF8, ou seja, pertence a ASCII, e retorna o comprimento de 1
   }else if (charleadingones == 1){
    return 0;   // se o primeiro byte é 1 então deve-se retornar 0 pois em UTF8 isso é invalido
   }else{
    return charleadingones; /*senão retorna o numero de 1's consecutivos, na tabela UTF8, se houver mais de 1 bit, 
                            a quantidade de bytes é a mesma da quantidade de 1s consecutivos*/
   }
}
// OBS: Não existe o primeiro byte a 1, pq o quando o elemento tem apenas um byte, ele esta no ASCCI (00 to 7F hex (0 to 127))
// De 2 byte pra frente frente, o nº de bytes e o mesmo do nº de  1 consecutivos
int main()
{  
    const char symbol1[] = {0x41};	// A
	const char symbol2[] = {0xC3, 0xA7};	//ç
	const char symbol3[] = {0xE2, 0x82, 0xAC};	//€
	const char symbol4[] = {"á"};
	

	printf("Tamanho do simbolo 1: %d\n", utf8Length(symbol1, 0));	//deve retornar 1
	printf("Tamanho do simbolo 2: %d\n", utf8Length(symbol2, 0));	//deve retornar 2
	printf("Tamanho do simbolo 3: %d\n", utf8Length(symbol3, 0));	//deve retornar 3
	printf("Tamanho do simbolo 4: %d\n", utf8Length(symbol4, 0));	//deve retornar 2

	printf("Tamanho da posicao subsequente do simbolo 1: %d\n", utf8Length(symbol2, 1));	//deve retornar 0
	
	return 0; 
}
