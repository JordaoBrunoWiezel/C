include <stdio.h>
#include <stdbool.h>

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
    int num_books;
} library_t;

// c) [3] Implemente a função calculate_total_price que calcula o preço total de todos os livros na biblioteca.
// A função deve receber a biblioteca como parâmetro e retornar o preço total.
float calculate_total_price(const library_t *library){

    float preco = 0.0;

    for(int i = 0; i <= library -> num_books; i++){
        preco += library->books[i].price
    }
return preco;
}