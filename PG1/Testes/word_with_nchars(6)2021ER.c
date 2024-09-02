#include <stdio.h>

// Definição das estruturas e constantes
#define MAX_WORD_SIZE 20
#define MAX_WORDS 5000

typedef struct {
    int nchars;
    char word[MAX_WORD_SIZE];
} Word;

typedef struct {
    int nwords;
    Word words[MAX_WORDS];
} Dictionary;

#define MAX_WORDS 5000

// Função para contar palavras com um número específico de caracteres
int words_with_nchars(Dictionary *dic, int num_chars) {
    int count = 0;

    for (int i = 0; i < dic->nwords; i++) {
        if (dic->words[i].nchars == num_chars) {
            count++;
        }
    }

    return count;
}

int main() {
    // Exemplo de uso
    Dictionary myDictionary;
    myDictionary.nwords = 3;

    Word word1 = {5, "apple"};
    Word word2 = {6, "banana"};
    Word word3 = {5, "grape"};

    myDictionary.words[0] = word1;
    myDictionary.words[1] = word2;
    myDictionary.words[2] = word3;

    int result = words_with_nchars(&myDictionary, 5);

    printf("Total de palavras com 5 caracteres: %d\n", result);

    return 0;
}
