#include <stdio.h>

#define MAX_ISBN 20

typedef struct { // Descritor dos dados de um livro
 char *title; // string alojada dinamicamente
 char isbn[MAX_ISBN]; // string com dimensão fixa
 char *authors; // string alojada dinamicamente
 char *publisher; // string alojada dinamicamente
} Book;

typedef struct{ // Descritor de um vetor
 Book **refs; // array alojado dinamicamente
 int size; // quantidade de elementos preenchidos
 int space; // quantidade de elementos alojados
} VecBookRef;

/* que procura, num vetor de livros, um livro com o isbn passado por parâmetro. A função retorna uma
referência para o livro com o isbn passado por parâmetro, caso exista, e retorna NULL caso não seja
encontrado qualquer livro.
*/

Book *find_isbn(VecBookRef *vec, char *isbn) {
    for (int i = 0; i < vec->size; i++) {
        if (strcmp(vec->refs[i]->isbn, isbn) == 0) {
            return vec->refs[i];
        }
    }
    return NULL;
}


/* que remove de um vetor de livros a referência para o livro cujo isbn é passado por parâmetro. A função
mantém o vetor ordenado e retorna: 0 se nenhum livro foi removido (porque não existia qualquer livro com
aquele isbn); um valor diferente de 0 caso tenha havido remoção. A função delete_book não elimina o
descritor de livro referenciado pela posição eliminada no vetor. 
*/

int delete_book(VecBookRef *vec, char *isbn) {
    int index = -1;
    
    // Procurar o índice do livro com o ISBN fornecido
    for (int i = 0; i < vec->size; i++) {
        if (strcmp(vec->refs[i]->isbn, isbn) == 0) {
            index = i;
            break;
        }
    }
    
    // Se o livro não for encontrado, retornar 0
    if (index == -1) {
        return 0;
    }
    
    // Deslocar os elementos subsequentes uma posição para a esquerda
    for (int i = index; i < vec->size - 1; i++) {
        vec->refs[i] = vec->refs[i + 1];
    }
    
    // Reduzir o tamanho do vetor
    vec->size--;
    
    // Retornar 1 para indicar que o livro foi removido
    return 1;
}

/* que se destina a inserir no vetor, indicado por vec, um novo elemento para referenciar o livro indicado por
b, mantendo o vetor ordenado e sem repetições. Se já existir um elemento igual, não se realiza qualquer
modificação. A função deve assegurar espaço no vetor, alojado dinamicamente, para o novo elemento; se
necessário, deve redimensionar o espaço, fazendo-o em blocos de 10 elementos, com recurso à função
realloc de biblioteca.
A função insert_book retorna: 0, caso o livro referenciado por b já exista no vetor; 1, em caso de
sucesso na inserção; -1, em caso de insucesso por falta de memória de alojamento dinâmico. Note que, caso
não haja memória dinâmica disponível, o vetor deve ser mantido inalterado.
Sugere-se que percorra o vetor sequencialmente para identificar o ponto de inserção do novo elemento. No
exercício desta alínea não deve utilizar a função qsort nem a função bsearch da biblioteca normalizada.
*/

int insert_book(VecBookRef *vec, Book *b) {
    // Verificar se o livro já existe no vetor
    for (int i = 0; i < vec->size; i++) {
        if (strcmp(vec->refs[i]->isbn, b->isbn) == 0) {
            return 0; // Livro já existe
        }
    }
    
    // Encontrar a posição correta para inserção
    int pos = 0;
    while (pos < vec->size && strcmp(vec->refs[pos]->isbn, b->isbn) < 0) {
        pos++;
    }
    
    // Redimensionar o vetor se necessário
    if (vec->size >= vec->space) {
        int new_space = vec->space + 10;
        Book **new_refs = (Book **)realloc(vec->refs, new_space * sizeof(Book *));
        if (new_refs == NULL) {
            return -1; // Falta de memória
        }
        vec->refs = new_refs;
        vec->space = new_space;
    }
    
    // Deslocar os elementos subsequentes para a direita
    for (int i = vec->size; i > pos; i--) {
        vec->refs[i] = vec->refs[i - 1];
    }
    
    // Inserir o novo livro
    vec->refs[pos] = b;
    vec->size++;
    
    return 1; // Sucesso na inserção
}