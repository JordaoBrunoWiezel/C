

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Doc
typedef struct {
    int class;      // Classificação principal
    int subclass;   // Classificação secundária
    char *desc;     // Descrição (string alojada dinamicamente)
} Doc;

// Definição da estrutura LNode
typedef struct lNode {
    struct lNode *next; // Ligação na lista
    Doc *ref;           // Referência: ponteiro para o elemento de informação
} LNode;

int docCompare(Doc *doc1, Doc *doc2) {
    if (doc1->class != doc2->class) {
        return doc1->class - doc2->class;
    }
    if (doc1->subclass != doc2->subclass) {
        return doc1->subclass - doc2->subclass;
    }
    return strcmp(doc1->desc, doc2->desc);
}

// Função listRemove
Doc *listRemove(LNode **headAddr, Doc *docData) {
    LNode *current = *headAddr;
    LNode *previous = NULL;

    while (current != NULL) {
        if (docCompare(current->ref, docData) == 0) {
            // Encontrou o nó para remover
            if (previous == NULL) {
                // O nó a ser removido é o primeiro da lista
                *headAddr = current->next;
            } else {
                // O nó a ser removido está no meio ou no final da lista
                previous->next = current->next;
            }

            Doc *removedDoc = current->ref;
            free(current);
            return removedDoc;
        }

        previous = current;
        current = current->next;
    }

    // Não encontrou o nó com o conteúdo indicado
    return NULL;
}

// Função refDelete
int refDelete(LNode **headAddr, Doc *docData) {
    Doc *docToDelete = listRemove(headAddr, docData);
    if (docToDelete == NULL) {
        // O elemento pretendido não existe na lista
        return 0;
    }

    // Libera a memória alocada para o elemento de dados
    free(docToDelete->desc);
    free(docToDelete);

    return 1;
}



