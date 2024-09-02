/*
Relativamente a cada um dos módulos compilados correspondentes, m1.o, m2.o e m3.o, apresente as
listas com os símbolos e a respetiva classificação (T, public text; t, private text; U, undefined.).
Nota que nome de função faux, existe em dois módulos, m1.c e m2.c. Diga o se é possível integrar o
código destes dois módulos, simultaneamente, no executável de uma aplicação; justifique. 

m1.o
00000000 t faux
00000014 T f1
         U f2

m2.o
00000000 t faux
00000014 T f2
         U printf

m3.o
00000000 T f3
         U f2

A função faux existe em ambos m1.c e m2.c, mas como elas são declaradas static, elas têm visibilidade limitada ao respectivo arquivo de origem. 
Isso significa que não haverá conflito de nomes durante a linkagem.
As funções f1, f2 e f3 têm visibilidade global, mas seus nomes não entram em conflito.
*/

/*
Indique quais os header files que cada módulo deve incluir. Complete o módulo m3.c com as diretivas
de inclusão e apresente os motivos para incluir, neste módulo, cada um dos header files que considerar

m1.c
#include "m1.h"

m2.c
#include "m2.h"
#include <stdio.h> // Para printf

m3.c
#include "m2.h"
#include <stdio.h> // Para printf

Uma diretiva de inclusão é uma instrução no código-fonte de um programa que informa ao compilador que ele deve 
incluir o conteúdo de outro arquivo no ponto onde a diretiva aparece. Em C e C++, a diretiva de inclusão é #include. 
Essa diretiva é utilizada principalmente para incluir arquivos de cabeçalho (.h) que contêm declarações de funções, 
macros, constantes e outras definições necessárias para a compilação de um programa.

#include "m3.h"
#include "m2.h" // Para a função f2

// Implementação das funções em m3.c
int f3(int x, int y) {
    f2(x);
    return y;
}


Controle de inclusão multipla:
#ifndef MEU_HEADER_H
#define MEU_HEADER_H

// Declarações e definições do arquivo de cabeçalho

#endif // MEU_HEADER_H

*/