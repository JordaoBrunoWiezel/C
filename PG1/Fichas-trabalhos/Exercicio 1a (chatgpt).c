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

// a) [2] Implemente a função add_book que adiciona um novo livro à biblioteca.
// Se a biblioteca estiver cheia ou se o livro já existir, a função deve retornar false.
bool add_book(library_t *library, const book_t *new_book){


    if(library -> num_books >= MAX_BOOKS ){
        return false;
    }

    for(int i = 0; i < library -> num_books, i++){
        if (strcmp(library->books[i].title, new_book->title) == 0 && strcmp(library->books[i].author, new_book->author) == 0) {
            return false;
        }
    }

library -> books[library -> num_books] = *new_book;
library -> num_books++;
return true;
}
