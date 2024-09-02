#include <stdio.h>
#include <string.h>

typedef struct waiter {
 struct waiter *next; // ligação em lista
 char *name; // nome do utente; alojar dinamicamente
} Waiter;

typedef struct {
    Waiter *front; // Ponteiro para o primeiro nó da fila
    Waiter *rear; // Ponteiro para o último nó da fila
} Queue;

/*que coloca na fila q um novo elemento, associando ao respetivo campo name uma cópia, alojada
dinamicamente, da string sn. Assuma, por simplificação, que nunca ocorre falta de memória para
alojamento dinâmico.*/

void qPut( Queue *q, char *sn )
{
    Waiter *newnode = (Waiter *) malloc(sizeof(*newnode));
    if(newnode == NULL) return;

        newnode->name = strdup(sn);
        if(newnode->name == NULL) {free(newnode); return;}
        newnode->next = NULL;
        
        if(q->rear == NULL) // se a fila estiver vazia
        {
            q->front = newnode;
            q->rear = newnode;
        }
        else {
            q->rear->next = newnode;
            q->rear = newnode;
        }
}

/* destinada a obter, retirando da fila, o elemento mais antigo. A função retorna: 1, em caso de sucesso; 0, se a
fila estiver vazia.
Quando retira um elemento, deve copiar o nome que ele contém para o espaço indicado por dn e libertar
toda a memória de alojamento dinâmico usada no elemento. Assuma, por simplificação, que o espaço
apontado por dn é suficiente para depositar o nome.
*/

int qGet( Queue *q, char *dn )
{
    // Se a fila estiver vazia, retorna 0
    if (q->front == NULL) {
        return 0;
    }

    // Nó para remover da fila
    Waiter *temp = q->front;

    // Copia o nome para o buffer fornecido
    strcpy(dn, temp->name);

    // Move o ponteiro front para o próximo nó
    q->front = q->front->next;

    // Se o front se tornar NULL, a fila está vazia, então rear deve ser NULL também
    if (q->front == NULL) {
        q->rear = NULL;
    }

    // Libera a memória do nó removido
    free(temp->name);
    free(temp);

    return 1;
}


// que retorna a quantidade de elementos existentes na fila. 

int qCount(Queue *q) {
    int count = 0;
    Waiter *current = q->front;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}