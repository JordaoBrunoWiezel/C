#include <stdio.h>

typedef struct{
 char filename[MAX_FILENAME + 1];
 char title[MAX_TITLE + 1];
 char artist[MAX_ARTIST + 1];
 char album[MAX_ALBUM + 1];
 short year;
 char comment[MAX_COMMENT + 1];
 char track;
 char genre;
} TagData;

//(…)
size_t f1( TagData a[], size_t nElem, int (*action)(TagData *data, void *context), void * context ){
 size_t s = 0;
 while(nElem--)
 s += (*action)(a++, context);
 return s;
 }
/*
(10)int main(){
(11) (…) // Alojamento e preenchimento do array a
(12) size_t nElem = sizeof(a) / sizeof(a[0]);
(13) size_t n1 = f1(…);
(14) char highTrack = 10;
(15)size_t n2 = f1(…);
(16)(…)
(17)return 0;
(18)}
*/

/* Escreva a função showAllTitles que, quando usada, na linha 13, como um dos
argumentos da função f1, produzirá em standard output a afixação do campo title de todas
as tags existentes no array a. A função deve retornar um valor tal que a variável n1 fique com o
valor da contagem de todas as tags existentes no array. Transcreva a linha 13 para a folha da sua
prova completando a chamada da função f1 com os argumentos corretos. 
*/

int ShowAllTitles(TagData *data, void *context)
{
    printf("%s\n", data->title);
    return 1;
}

// size_t n1 = f1(a, nElem, ShowAllTitlesm, NULL);

/* Escreva a função showHighTracks que, quando usada como consta na linha 15, produzirá
em standard output a afixação do campo album de todas as tags que existem no array a e cuja
faixa (campo track) é superior a um valor passado por parâmetro e contido na variável
highTrack, iniciada na linha 14. Admita que todas as tags têm no campo album uma string
válida, devidamente terminada, e têm o campo track devidamente preenchido. A função deve
retornar um valor tal que a variável n2 fique com o valor da contagem das tags cujo n.º da faixa
é superior ao valor contido na variável highTrack. Transcreva a linha 15 para a folha da sua
prova completando a chamada da função f1 com os argumentos corretos. 
*/

int showHighTrack(TagData *data, void *context)
{
    char hightrack = *(char*)context; 
    if(data->track > hightrack)
    {
        printf("Album: %s",data->album);
        return 1;
    }
return 0;
}
/*
char highTrack = 10;
 size_t n2 = f1(a,nElem,showHighTracks,&hightrack);
*/

/*Considere que se pretende agora realizar uma função f1a com a mesma funcionalidade da
função f1 mas com maior generalidade, que possa operar sobre arrays de outros tipos e não
apenas arrays de elementos do tipo TagData. Sendo uma versão da função f1, a função f1a
deve seguir de muito perto o algoritmo da função f1.
Escreva a definição da função f1a, adicionando ou removendo parâmetros se necessário. Escreva
a definição da função com uma indentação correta, usando obrigatoriamente comentários.
Rescreva a linha 15, onde é usada a função f1, no exemplo de utilização anterior, substituindo-a
pela utilização da função f1a, igualmente aplicada ao array a
*/

size_t f1a(void *arr, size_t nElem, size_t elemSize, int (*action)(void *data, void *context), void *context) {
    size_t s = 0;
    char *ptr = (char *)arr; // Usa um ponteiro char para iterar sobre os elementos genericamente
    while (nElem--) {
        s += (*action)(ptr, context);
        ptr += elemSize; // Avança o ponteiro para o próximo elemento
    }
    return s;
}

//size_t n2 = f1a(a, nElem, sizeof(TagData), showHighTracks, &highTrack);