#include <stdio.h>

typedef struct{
 int number; // Número de identificação
 char *name; // Nome (string alojada dinamicamente)
 char *function; // Cargo desempenhado (string alojada dinamicamente)
} Member; 

typedef struct listStaff{
 struct listStaff *next; // ligação na lista
 Member *ref; // referência: ponteiro para o elemento de dados
} ListStaff; 

typedef struct bstStaff{
 struct bstStaff *left, *right; // ligações na árvore
 Member *ref; // referência: ponteiro para o elemento de dados
} BstStaff; 


//que procura, na árvore identificada por root, o nome indicado por name e retorna o respetivo número de identificação. 
// Se o nome indicado não existir, deve retornar o valor «-1». 


// OPÇÃO 1

int bstGetNumber(BstStaff *root, char *name) {
    // Enquanto houver nós na árvore para explorar
    while (root != NULL) {
        int cmp = strcmp(name, root->ref->name);
        
        if (cmp == 0) {
            // Nome encontrado
            return root->ref->number;
        } else if (cmp < 0) {
            // Nome é menor do que o nome no nó atual, ir para a esquerda
            root = root->left;
        } else {
            // Nome é maior do que o nome no nó atual, ir para a direita
            root = root->right;
        }
    }
    
    // Nome não encontrado
    return -1;
}

// OPÇÃO 2

int bstGetNumber(BstStaff *root, char *name) {

        if(root == NULL) {
        return -1; // Nome não encontrado
    }

        /*
        if(root == NULL) //cria um nó
        {
            root = malloc(sizeof(BstStaff));
            if(root == NULL) return 0;
            (root)->ref = name;
            (root)->left = (root)->right = NULL;
            return root->ref->number;
        }
        */

    // Ver se o elemento existe na arvore
    int cmp = strcmp(name, root->ref->name);
    if(cmp == 0) return root->ref->number; //ja existe
    if(cmp < 0) return bstGetNumber(root->left, name);
    else return bstGetNumber(root->right, name);
}



/*
Admita que existe uma árvore binária com 31 nós, perfeitamente balanceada, e é chamada a
função bstGetNumber, podendo o nome existir ou não na árvore. Indique e justifique as
quantidades mínima e máxima de nós da árvore que pode ser necessário observar, para comparar
com a string do parâmetro name. Na identificação das quantidades pedidas, tenha em conta o
comportamento do algoritmo implementado na alínea anterior (podendo este ser, por exemplo,
recursivo ou iterativo). 


Árvore Binária de Pesquisa Perfeitamente Balanceada:

Uma árvore binária de pesquisa perfeitamente balanceada tem a seguinte propriedade:

Para uma árvore com n nós, a altura da árvore é ⌊log⁡2(𝑛)⌋
Com 31 nós, a altura da árvore é ⌊log2(31)⌋=4

Isso significa que a árvore tem uma altura de 4, e cada nível da árvore está completamente preenchido até o nível 4.


Análise da Função bstGetNumber:

A função bstGetNumber implementa uma busca binária na árvore:

Em cada nó, compara o nome procurado (name) com o nome armazenado no nó atual (root->ref->name).
Se o nome é encontrado, a busca termina.
Se o nome é menor, a busca continua na subárvore esquerda.
Se o nome é maior, a busca continua na subárvore direita.


Quantidade Mínima de Nós Observados:

Caso Melhor (Nome Encontrado no Primeiro Nó):

No melhor caso, o nome procurado é encontrado no nó raiz da árvore.
Apenas um nó é observado.
Quantidade mínima de nós observados: 1.


Quantidade Máxima de Nós Observados:

Caso Pior (Nome Não Encontrado e Busca Até a Folha Mais Profunda):

No pior caso, o nome procurado não está na árvore e a busca continua até uma folha, ou seja, a profundidade máxima da árvore.
Em uma árvore de altura 4, a busca pode percorrer até 5 níveis (raiz + 4 níveis de profundidade).
Para uma árvore de 31 nós, que é perfeitamente balanceada:

A árvore tem 5 níveis no total (nível 0 a nível 4).
No pior caso, a busca terá que comparar o nome procurado com todos os nós ao longo de um caminho da raiz até uma folha.
Quantidade máxima de nós observados: 5.

Resumo:
Quantidade mínima de nós observados: 1 nó (nome encontrado na raiz).
Quantidade máxima de nós observados: 5 nós (nome não encontrado, e a busca percorre até a folha mais profunda).
*/