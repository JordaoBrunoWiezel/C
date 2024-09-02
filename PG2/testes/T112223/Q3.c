#include <stdio.h>
#include <string.h>

#define MAX_ARTIST 100
#define MAX_TITLE 100

typedef struct tNode {
    struct tNode *left, *right; // Ponteiros para os nós esquerdo e direito
    char artist[MAX_ARTIST + 1]; // Nome do artista
    char title[MAX_TITLE + 1]; // Título da obra
    char *filename; // Nome do ficheiro (alojamento dinâmico)
    double duration; // Duração da obra em minutos
} TNode;

int tPrintByDuration(TNode *r, double dur) {
    if (r == NULL) {
        return 0; // Se a árvore está vazia, retorna 0
    }

    int count = 0;

    // Percorre toda a subárvore esquerda ate achar nulo, quando achar, vai voltando e executando
    count += tPrintByDuration(r->left, dur);

    // Verifica e imprime o nó atual se a duração for superior a dur
    if (r->duration > dur) {
        printf("Artista: %s, Título: %s, Duração: %.2f minutos, Ficheiro: %s\n",
               r->artist, r->title, r->duration, r->filename);
        count++;
    }

    // Percorre a subárvore direita
    count += tPrintByDuration(r->right, dur);

    return count; // Retorna a quantidade de obras apresentadas
}

/* Exemplo de arvore:
      node1 ("Artist B", "Title 1", 4.0)
     /                               \
 node2                              node3
("Artist A", "Title 2", 2.0)  ("Artist C", "Title 3", 5.5)
                                        \
                                        node4
                                ("Artist D", "Title 4", 3.5)

*/


/* que apresenta, em standard output, o título, duração e ficheiro das obras do artista indicado por
art. Os dados devem ser apresentados pela ordem crescente da árvore. Retorna a quantidade de
obras apresentadas. Valoriza-se a eficiência, devendo ser evitados percursos em partes
desnecessárias da árvore.
*/ 

// mesmo coisa q a de cima, so muda a comparação
int tPrintByArtist(TNode *r, char *art) {
    if (r == NULL) {
        return 0; // Se a árvore está vazia, retorna 0
    }

    int count = 0;

    // Percorre a subárvore esquerda
    count += tPrintByArtist(r->left, art);

    // Verifica e imprime o nó atual se o artista for igual a art
    if (strcmp(r->artist, art) == 0) {
        printf("Título: %s, Duração: %.2f minutos, Ficheiro: %s\n",
               r->title, r->duration, r->filename);
        count++;
    }

    // Percorre a subárvore direita
    count += tPrintByArtist(r->right, art);

    return count; // Retorna a quantidade de obras apresentadas
}


//que elimina a árvore com raiz indiada por r, libertando a memória de alojamento dinâmico usada nos seus nós e nas strings dependentes deles.

void tDelete(TNode *r) {
    if (r == NULL) {
        return; // Se a árvore está vazia, retorna
    }

    // Elimina a subárvore esquerda
    tDelete(r->left);

    // Elimina a subárvore direita
    tDelete(r->right);

    // Libera a memória alocada dinamicamente para o nome do ficheiro
    free(r->filename);

    // Libera a memória do próprio nó
    free(r);
}