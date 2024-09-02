#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct{
 int code; // Código de reserva
 char start[3+1]; // Aeroporto de partida
 char end[3+1]; // Aeroporto de chegada
 char *desc; // Descrição do voo (string alojada dinamicamente)
} Flight; 

typedef struct listFlight{
 Flight *flight;
 struct listFlight *next;
} ListFlight; 

typedef struct bstFlight{
 char end[3+1];
 ListFlight *subset;
 struct bstFlight *left, *right;
} BstFlight; 

/* Escreva a função
void bstInsert(BstFlight **rootAddr, Flight *flight);
que insere no subconjunto adequado, pertencente a uma árvore, o elemento indicado por flight,
previamente alojado e preenchido. O parâmetro rootAddr representa o endereço do ponteiro
raiz da árvore binária. Se ainda não existir o subconjunto adequado para o elemento, deve ser
criado um nó para o suportar.
Para inserir o voo na lista ligada, deve utilizar a função listInsert que se assume já existir,
com a assinatura seguinte.
 void listInsert(ListFlight **headAddr, Flight *flight); 
*/

// void listInsert(ListFlight **headAddr, Flight *flight);


int bstInsert(BstFlight **rootAddr, Flight *flight) {
    //cria um novo nó da árvore
    if (*rootAddr == NULL) {
        *rootAddr = (BstFlight *)malloc(sizeof(BstFlight));
        if (*rootAddr == NULL) return 0; // Falha ao alocar memória

        strcpy((*rootAddr)->end, flight->end);
        (*rootAddr)->subset = NULL;
        (*rootAddr)->left = (*rootAddr)->right = NULL;
        listInsert(&(*rootAddr)->subset, flight);
        return 1; // Sucesso
    }

    // Comparar o aeroporto de chegada do voo com o aeroporto do nó atual
    int cmp = strcmp(flight->end, (*rootAddr)->end);
    if (cmp < 0) 
        // Inserir na subárvore esquerda
        return bstInsert(&(*rootAddr)->left, flight);
    else if (cmp > 0)
        // Inserir na subárvore direita
        return bstInsert(&(*rootAddr)->right, flight);
    else {
        // Aeroporto de chegada é igual, inserir na lista ligada do nó atual
        listInsert(&(*rootAddr)->subset, flight);
        return 1; // Sucesso
    }
}

/* Admita que existe uma árvore binária com 15 nós, perfeitamente balanceada, e é chamada a
função bstInsert, com um voo, podendo já existir na árvore, ou não, outros voos com o
mesmo destino. Indique e justifique, tendo em conta a possibilidade de chamada recursiva, as
quantidades mínima e máxima de chamadas à função bstInsert para realizar esta inserção.
Nos seus cálculos, deve incluir a chamada à função bstInsert a partir do programa de
aplicação.
*/

/* Para determinar a quantidade mínima e máxima de chamadas à função bstInsert em uma árvore binária de busca (BST) perfeitamente balanceada 
com 15 nós, precisamos considerar a natureza das operações em uma BST e a estrutura da árvore.

Estrutura de uma BST Perfeitamente Balanceada
Uma árvore binária perfeitamente balanceada com 15 nós terá uma estrutura completa, onde cada nó possui zero ou dois filhos até o penúltimo 
nível. A profundidade (ou altura) de tal árvore será 3 (considerando a raiz como nível 0).

Cálculo da Quantidade de Chamadas
Quantidade Mínima de Chamadas
A quantidade mínima de chamadas ocorre quando o nó a ser inserido está na raiz da árvore ou o destino já existe no nó da raiz.

Chamadas Mínimas:
Uma única chamada para verificar a raiz e inserir o elemento na lista ligada do nó raiz (caso o destino já exista no nó raiz).
Portanto, a quantidade mínima de chamadas é 1.

Quantidade Máxima de Chamadas
A quantidade máxima de chamadas ocorre quando a função precisa percorrer a maior profundidade da árvore para encontrar a posição correta de 
inserção.

Chamadas Máximas:
Em uma árvore perfeitamente balanceada de altura 3, o número máximo de comparações ocorre ao percorrer do nível 0 até o nível 3 (4 níveis no 
total).
A cada nível, uma comparação é feita e, possivelmente, uma chamada recursiva é realizada até alcançar a folha ou o nó apropriado para inserção.
Portanto, a quantidade máxima de chamadas é 4.

Resumo
Quantidade Mínima de Chamadas: 1 (se o destino já está no nó raiz).
Quantidade Máxima de Chamadas: 4 (se o destino não existe e precisa ser inserido na folha mais profunda).

Justificativa
A justificativa baseia-se na natureza das operações em uma BST balanceada:

Caso mínimo: Se o destino do voo a ser inserido já existe no nó raiz, a função bstInsert é chamada apenas uma vez, e o voo é inserido na 
lista ligada correspondente.
Caso máximo: Para encontrar a posição de inserção correta, a função bstInsert pode percorrer até a profundidade da árvore. Em uma árvore 
perfeitamente balanceada de 15 nós (altura 3), isso implica no máximo 4 chamadas (nível 0 a nível 3).
Ilustração
Considere a árvore perfeitamente balanceada com 15 nós:

markdown
Copy code
       8
     /   \
    4     12
   / \   /  \
  2   6 10  14
 / \ / \/ \ / \
1  3 5 7 9 11 13 15

Chamadas Mínimas (1 chamada):
Inserir um voo com destino 8 (se já existe um voo com destino 8 no nó raiz).
Chamadas Máximas (4 chamadas):
Inserir um voo com destino 15 (ou qualquer destino que deve ser inserido na folha mais profunda).
Portanto, a análise e justificativa acima mostram que a quantidade mínima de chamadas à função bstInsert é 1, enquanto a quantidade máxima é 4, 
para uma árvore binária perfeitamente balanceada com 15 nós.
*/