
/*
#include <stdio.h>

int show(int *e, void * p){
 printf("%d ", *e);
 return 1;
} 
int f1(int a[], int size, int (*cond)(const int * e), int (*act)(int *data, void *context), void * context) {
 int i, s=0;
 for(i = 0; i < size; i++)
 if(cond == NULL || cond(a+i))
 s += act(a+i, context);
 return s;
}

int main()
{
int r = 0;
int a[20] = {-4, 3, -1, -3, 0, 4, -7, -8, -6, 5, -9, 7, -5, 8, 0, 6, 2, 1, 9, -2};

int size=20;

r = f1(a, size, NULL, show, NULL);
printf("\n%d", r); 
}
 2.a Standard output; -4 3 -1 -3 0 4 -7 -8 -6 5 -9 7 -5 8 0 6 2 1 9 -2. Para um array de inteiros a, a + i é equivalente a &a[i].
Quando você faz a + i, está calculando o endereço do i-ésimo elemento do array a (aritmética de ponteiros)
O r = 20, porque s vai interando com cada return da função show, como essa função retorna 1, o S soma 1 20 vezes.
*/


/*
#define ALG 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int show(int *e, void * p){
 printf("%d ", *e);
 return 1;
}
int f2(const int * e) {
 return (*e == ALG);
}
int chg(int * n, int * lim){
 int r = (*lim > 4);
 *n = r ? *n * *n : -*n;
 return r;
}

int f1(int a[], int size, int (*cond)(const int * e), int (*act)(int *data, void *context), void * context) {
 int i, s=0;
 for(i = 0; i < size; i++)
 if(cond == NULL || cond(a+i))
 s += act(a+i, context);
 return s;
} 

int main()
{
int r = 0, option=ALG;
int a[20] = {-4, 3, -1, -3, 0, 4, -7, -8, -6, 5, -9, 7, -5, 8, 0, 6, 2, 1, 9, -2};

int size=20;

r = f1(a, size, f2, chg, &option);
printf("\n%d", r);
}



2.b Standard output: -4, 3, -1, -3, 0, 4, -7, -8, -6, 25, -9, 7, -5, 8, 0, 6, 2, 1, 9, -2
Conteúdo da variável r: 1.

Justificação Detalhada
Cada elemento do array foi verificado por f2.
f2 só retornou verdadeiro para a[9] (valor 5).
A função chg modificou a[9] para 25 e retornou 1, incrementando r para 1.
Nenhum outro elemento foi modificado, porque f2 retornou falso para todos os outros valores.
*/





int f3(const int *e) { // A função f3 deve verificar se um elemento é um número par. 
    return (*e % 2 == 0);
} // Retorna 1 (verdadeiro) se for par e 0 (falso) caso contrário.


/*A função f4 deve substituir o valor do elemento pelo valor da variável option se a condição 
de f3 for satisfeita. Além disso, deve garantir que a soma dos retornos seja 10, o que implica 
que deve retornar 1 cada vez que modifica um elemento par (precisamos modificar 10 elementos pares no array).*/

int f4(int *data, void *context) {
    int *option = (int *)context;
    *data = *option;
    return 1;
}

/*
Após a execução de f1, todos os elementos pares do array a terão o valor de option, que é 5.
O valor de r será 10, pois há exatamente 10 elementos pares no array original.
Conteúdo do Array a Após Transformação:
5, 3, -1, -3, 5, 5, -7, 5, 5, 5, -9, 7, -5, 5, 5, 5, 5, 1, 9, 5
Valor de r: 10
*/