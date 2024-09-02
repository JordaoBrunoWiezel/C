#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
 char *desc; // descrição - string alojada dinamicamente
 int year; // ano
 short month; // mês
 short day; // dia
}Event; 

typedef struct bstEvPtr{
 struct bstEvPtr *left, *right;
 Event *ptr;
} BstEvPtr; 

/* que insere na árvore binária um novo nó associado ao elemento indicado por event, que já existe
no instante de inserção, previamente alojado e preenchido. Em caso de sucesso, retorna 1; se já
existir um evento com a descrição igual, não deve modificar a árvore e retorna 0
*/

int bstInsert(BstEvPtr **rootAddr, Event *event)
{
    if(*rootAddr == NULL) //cria um nó
    {
        *rootAddr = malloc(sizeof(BstEvPtr));
        if(*rootAddr == NULL) return 0;
        (*rootAddr)->ptr = event;
        (*rootAddr)->left = (*rootAddr)->right = NULL;
        return 1;
    }
    
    // Ver se o elemento existe na arvore
    int cmp = strcmp(event->desc, (*rootAddr)->ptr->desc);
    if(cmp == 0) return 0; //ja existe
    if(cmp < 0) return bstInsert(&(*rootAddr)->left, event);
    else return bstInsert(&(*rootAddr)->right, event);
}

/* destinada a procurar na árvore indicada por root, a descrição indicada por desc e apresentar a
respetiva data, em standard output. Em caso de sucesso, retorna 1; Se a string pesquisada não
existir, não apresenta nada e retorna 0
*/

int bstPrintEvent(BstEvPtr *root, char *desc)
{
    if(root == NULL) return 0;
    int cmp = strcmp(desc, root->ptr->desc);
    if(cmp == 0) // encontrou
    {
        Event *e = root -> ptr;
        fprintf(stdout, "%d-%d-%d", e->year, e->month, e->day);
        return 1;
    }
    else if (cmp < 0)
        return bstPrintEvent(root->left, desc);
    else
        return bstPrintEvent(root->right, desc);
}