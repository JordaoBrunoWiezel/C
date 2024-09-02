#include <stdio.h>
#include <string.h>

typedef struct lNode{
 struct lNode *next; // ponteiro de ligação da lista
 char *word; // string, alojada dinamicamente, representando uma palavra
 int freq; // a frequência da palavra num ficheiro
} LNode; 

// que retorna o nó da lista que contém a palavra word, ou NULL caso não exista.

LNode* findWord( LNode* head, char* word )
{
    LNode *current = head;

    while(current != NULL)
    {
        if(strcmp(current->word, word) == 0)
            return current->word;
    current = current->next;
    }
    return NULL;
}

/* que adiciona uma nova palavra à lista, caso esta ainda não esteja presente. Caso já exista,
 incrementa o número de ocorrências da mesma. A função retorna a cabeça da lista. */ 

LNode* addWord( LNode* head, char* word )
{
    LNode *wordfound = findWord(head, word);
    if(wordfound != NULL) {wordfound->freq++; return head;}

    // Se não for encontrada, cria um novo nó
    LNode *newnode = (LNode *) malloc(sizeof(*newnode));
    if(newnode == NULL) return;

    //alojamento dinamico para a nova palavra
    newnode->word = (char *)malloc(strlen(word)+1);
    if(newnode->word == NULL) {free(newnode); return;}

    // Coloquei a nova nova palavra no nó criado
    strcpy(newnode->word, word);
    newnode->freq = 1;

    /* em vez de fazer o alojamento dinamico e o strcpy, posso so fazer o strdup q faz os dois:

    newNode->word = strdup(word);
    if (newNode->word == NULL) free(newNode);
    */

    // Insere um novo nó no inicio da lista
    newnode->next = NULL;
    newnode->next = head;
    head = newnode;

    return head;
}

/* que retorna uma nova lista com as mesmas palavras contidas em list1 e list2. A nova lista
deve ter as palavras provenientes das duas listas originais, sem repetição; cada palavra deve ter a
soma das respetivas ocorrências em ambas as listas. Serão valorizadas as soluções que tenham
em conta o desempenho da execução.
*/


//Opção 1: caso toda palavra adicionada numa lista se torna a cabeça

LNode* mergeLists(LNode* list1, LNode* list2) {
    LNode* mergedList = NULL;
    LNode* current = list1;

    // Adiciona todas as palavras da primeira lista à lista mesclada
    while (current != NULL) {
        mergedList = addWord(mergedList, current->word);
        mergedList->freq = current->freq;  // Ajusta a frequência para igualar à da lista original
        current = current->next;
    }

    // Adiciona todas as palavras da segunda lista à lista mesclada
    current = list2;
    while (current != NULL) {
        LNode* nodeInMergedList = findWord(mergedList, current->word);
        if (nodeInMergedList != NULL) {
            nodeInMergedList->freq += current->freq;  // Incrementa a frequência
        } else {
            mergedList = addWord(mergedList, current->word);
            mergedList->freq = current->freq;  // Ajusta a frequência
        }
        current = current->next;
    }

    return mergedList;
}

// Opção 2: Caso possa adicionar uma palavra sem esta se tornar uma cabeça

LNode* mergeLists( LNode* list1, LNode* list2 )
{
    LNode *mergedList = NULL;

    LNode *current = list1;
    while(current != NULL){
        mergedList = addWord(mergedList, current->word);
        LNode *nodeInMergedList = findWord(mergedList, current->word); // retorna o no da lista com a palavra word recem adicionado
        nodeInMergedList->freq = current->freq; // coloca a palavara com o msm nº de frequencia da lista1
        current = current->next;
    }

    current = list2;
    while(current != NULL){
            LNode *nodeInMergedList = findWord(mergedList, current->word);
        if(nodeInMergedList != NULL) // caso a palavra existe, apenas incrementa a frequencia;
            nodeInMergedList->freq += current->freq;
        else { // caso nao exista, adiciona a palavra e coloca com o msm º de frequencia
            mergedList = addWord(mergedList, current->word);
            nodeInMergedList = findWord(mergedList, current->word);
            nodeInMergedList->freq = current->freq;
        }
        current = current->next;
    }
    return mergedList;
}



// Exemplo de uma função para inserir um nó na ordem crescente:

void insertOrdered(LNode** head, int freq) {
    LNode* newNode = createNode(freq);

    // Caso a lista esteja vazia ou o novo nó precise ser inserido no início
    if (*head == NULL || (*head)->freq >= freq) {
        newNode->next = *head;
        *head = newNode;
    } else {
        LNode* current = *head;
        // Encontra a posição correta para o novo nó
        while (current->next != NULL && current->next->freq < freq) {
            current = current->next;
        }
        newNode->next = NULL;
        newNode->next = current->next;
        current->next = newNode;
    }
}
