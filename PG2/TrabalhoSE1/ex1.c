#include <stdio.h>
#include <limits.h>

/*Escreva a função int charLeadingOnes( char value ); 
que retorna o número de bits consecutivos com o valor 1, contados a partir do bit de maior peso do 
parâmetro value. */ 

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

int main()
{
    char value = 0b11100000;
    int resp;

    resp = charLeadingOnes(value);

    printf("%d\n", resp);
    return 0;
}
