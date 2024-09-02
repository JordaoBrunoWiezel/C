#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOKS 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
    float price;
} book_t;

typedef struct {
    book_t books[MAX_BOOKS];
    int num_books;  // Numero de books disponiveis
} library_t;


// b) [3] Implemente a função find_books_by_author que imprime todos os livros de um autor específico.
// A função deve receber a biblioteca e o nome do autor como parâmetros.
void find_books_by_author(const library_t *library, const char *author_name){

    for(int i = 0; i < library -> num_books; i++){
        if(strcmp(library->books[i].author, author_name) == 0){
            printf("%s", title[i]);
        }
    }

}