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


int count_word_anagrams(Dictionary *dic, Word word) {
    int anagramCount = 0;

    // Obtém as contagens de letras da palavra fornecida
    LettersCount wordCount;
    word_letters_count(word, wordCount);

    // Percorre o dicionário para verificar anagramas
    for (int i = 0; i < dic->nwords; i++) {
        // Obtém as contagens de letras da palavra no dicionário
        LettersCount dicWordCount;
        word_letters_count(dic->words[i], dicWordCount);

        // Compara as contagens para determinar se são anagramas
        int j;
        for (j = 0; j < 'Z' - 'A' + 1; j++) {
            if (wordCount[j] != dicWordCount[j]) {
                break;
            }
        } 
        // Se todas as contagens forem iguais, são anagramas
            if (j == 'Z' - 'A' + 1) {
                anagramCount++;
            }
        }

    return anagramCount;
}



