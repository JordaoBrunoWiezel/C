#include <stdio.h>

// para guardar as ocorrência de letras de uma
// palavra ou texto. Na primeira posição guarda a
// contagem de A’s (maiúsculos ou minúsculos), até à
// última posição onde é guardada a contagem de Z’s.
typedef int LettersCount['Z' - 'A' + 1];


#define MAX_WORD_SIZE 20 // dimensão máxima de uma palavra

// para facilitar a obtenção do tamanho da palavra
typedef struct {
 int nchars; // total de caracteres da palavra 
             // ex: “palavra” tem 7 caracteres
 char word[MAX_WORD_SIZE]; // caracteres da palavra
} Word;

// guarda em lc as ocorrências de letras da palavra w
void word_letters_count(Word w, LettersCount lc);


#define MAX_WORDS 5000 // máximo de palavras num dicionário

typedef struct {
 int nwords; // total de palavras no dicionário
 Word words[MAX_WORDS]; // palavras do dicionário
} Dictionary;

int words_with_nchars(Dictionary *dic, int num_chars) {

    int contador = 0;

    for(int i= 0; i < dic->nwords; i++){
        if(dic-> words[i].nchars == num_chars){
        contador++;
        }
    }

return contador;
}


// FEITO PELO CHATGPT
int main() {
    // Exemplo de uso
    Dictionary myDictionary;

    // Inicialização fictícia do dicionário com algumas palavras
    myDictionary.nwords = 5;
    myDictionary.words[0].nchars = 3; snprintf(myDictionary.words[0].word, MAX_WORD_SIZE, "cat");
    myDictionary.words[1].nchars = 5; snprintf(myDictionary.words[1].word, MAX_WORD_SIZE, "apple");
    myDictionary.words[2].nchars = 3; snprintf(myDictionary.words[2].word, MAX_WORD_SIZE, "dog");
    myDictionary.words[3].nchars = 6; snprintf(myDictionary.words[3].word, MAX_WORD_SIZE, "orange");
    myDictionary.words[4].nchars = 4; snprintf(myDictionary.words[4].word, MAX_WORD_SIZE, "bird");

    // Teste da função
    int result = words_with_nchars(&myDictionary, 3);

    // Impressão do resultado
    printf("Total de palavras com 3 caracteres: %d\n", result);

    return 0;
}