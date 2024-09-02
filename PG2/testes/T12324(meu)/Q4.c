/*
a.
Tendo em conta a existência, em dois módulos, de funções com o mesmo nome (update),
indique, justificando, se estes dois módulos podem ser usados no mesmo executável. 

SIM. Os dois módulos podem ser usados no mesmo executável desde que a função update seja declarada como static.

Quando uma função é declarada como static em um arquivo fonte (.c), seu escopo é restrito a esse arquivo. 
Dessa forma, mesmo que ambas as funções tenham o mesmo nome, elas são tratadas como entidades completamente separadas pelo compilador 
porque suas visibilidades estão limitadas aos respectivos arquivos onde foram definidas.

Durante o processo de linkagem, funções static não causam conflitos de nome, porque elas não são adicionadas à tabela global de símbolos. 
Elas existem apenas no contexto do arquivo em que foram definidas.
Portanto, update em minArr.c e update em maxArr.c podem coexistir sem causar conflito, já que cada uma está restrita ao seu próprio arquivo.
*/

/*
c.
Tendo em conta as dependências existentes, identifique os módulos que devem ser ligados
ao módulo de aplicação (test.o) para gerar o executável. Escreva uma sequência de comandos
adequada para produzir os módulos compilados estritamente necessários e, a partir deles, o
executável com o nome “test”.

Dependências:
test.c depende de minArr.h, e consequentemente de min2.h para a função min2.
minArr.c depende de min2.h.
maxArr.c e max2.c não são necessários diretamente para este exemplo, mas se fossem usados, também seriam incluídos da mesma forma.

Sequência de comandos para compilar e ligar:

Compile min2.c em min2.o:
gcc -c min2.c -o min2.o

Compile minArr.c em minArr.o:
gcc -c minArr.c -o minArr.o

Compile test.c em test.o:
gcc -c test.c -o test.o

Ligar todos os arquivos objeto para criar o executável test:
gcc test.o minArr.o min2.o -o test

Makefile
Para automatizar esse processo, podemos escrever um Makefile:
*/