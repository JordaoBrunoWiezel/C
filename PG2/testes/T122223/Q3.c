#include <stdio.h>
#include <string.h>

typedef struct setNode {
    struct setNode *less, *great; // ligações na árvore
    double value; // número representado
} SetNode;

/* que insere um elemento com o valor v (se não existir) no conjunto representado por s. A função retorna o
ponteiro de acesso ao conjunto, eventualmente modificado pela inserção. */ 


SetNode *creatnode(double *v)
{
    SetNode *newnode = (SetNode *) malloc(sizeof(*newnode));
    if(newnode == NULL) {free(newnode); return;}

    newnode->value = (int)v; // ta errado
    newnode->less = NULL;
    newnode->great = NULL;

    return newnode;
}

SetNode *setInsert(SetNode *s, double v) {
    if (s == NULL) {
        // Se a árvore está vazia, cria um novo nó e retorna
        return createNode(v);
    }

    if (v < s->value) {
        // Se o valor é menor, insere na subárvore à esquerda
        s->less = setInsert(s->less, v);
    } else if (v > s->value) {
        // Se o valor é maior, insere na subárvore à direita
        s->great = setInsert(s->great, v);
    }
    // Se o valor já existe, não faz nada (conjuntos não têm valores repetidos)

    return s;
}

// que procura o elemento com o valor v no conjunto representado por s. A função retorna 1 se o valor v existe ou 0 no caso oposto

int setContains( SetNode *s, double v )
{   
    if (s == NULL) {
        return 0;
    }

    if (v == s->value) {
        return 1;
    } else if (v < s->value) {
        return setContains(s->less, v);
    } else {
        return setContains(s->great, v);
    }
}

/*que cria um novo conjunto formado pelos valores que existem em ambos os conjuntos originais, indicados
por s1 e s2. Retorna o ponteiro de acesso ao novo conjunto. Não modifica os conjuntos originais. */

SetNode *setIntersect(SetNode *s1, SetNode *s2) { // Provavelmnete esta errada
    if (s1 == NULL || s2 == NULL) {
        return NULL;
    }

    SetNode *result = NULL;

    // Percorre a árvore s1 e insere no resultado se o valor estiver em s2
    if (setContains(s2, s1->value)) {
        result = setInsert(result, s1->value);
    }

    // Recorre para as subárvores esquerda e direita de s1 
    SetNode *leftIntersect = setIntersect(s1->less, s2);
    SetNode *rightIntersect = setIntersect(s1->great, s2);

    // Mescla os resultados das subárvores esquerda e direita
    SetNode *temp = leftIntersect;
    while (temp != NULL) {
        result = setInsert(result, temp->value);
        temp = temp->great;
    }

    temp = rightIntersect;
    while (temp != NULL) {
        result = setInsert(result, temp->value);
        temp = temp->great;
    }

    return result;
}
