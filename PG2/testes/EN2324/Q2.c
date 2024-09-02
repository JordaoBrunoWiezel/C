#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define TAGDATA_ARRAY_SIZE 100 

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

typedef struct{
 TagData *data; // aponta para array de tags (o array tem alojamento estático)
 int space; // capacidade do array; quantidade de elementos
 int count; // quantidade de elementos preenchidos
 int (*comp)(const void *, const void *); // Função de comparação para
 // ordenar o array data.
} StoreArr; 

/*
(…)
int trackComp(const void *e1, const void *e2){
}
#define TAGDATA_ARRAY_SIZE 100
TagData a[TAGDATA_ARRAY_SIZE];
int main(){
 StoreArr sa;
 setupStoreArr(&sa, a, TAGDATA_ARRAY_SIZE, trackComp);
 Preenchimento de sa...
 sortStoreArr(&sa);
 TagData newTag;
 Preenchimento de newTag...
 if(insertOrd(&sa, &newTag))
 printf("Insercao bem sucedida\n");
 return 0;
} 
*/


/*que configura um descritor de um array do tipo StoreArr, no estado vazio mas com alojamento
(estático) já realizado para nElem elementos, registando internamente a função indicada por
comp, associada para utilização futura, como se exemplifica na linha 9 da caixa com troço de
código. 
*/
void setupStoreArr(StoreArr *a, TagData *data, int nElem, int(*comp)(const void*, const void*))
{

a ->count = 0;
a ->space = nElem;
a ->comp = comp;
a ->data = data;

}

/* que ordena o array pertencente ao descritor indicado por arr com o critério implementado pela
função de comparaç+ão associada, registada no campo comp. Tem de usar a função qsort da
biblioteca normalizada. */
void sortStoreArr(StoreArr *arr)
{
    qsort(arr->data, arr->count, sizeof(TagData), arr->comp)

/*
• base – Endereço do array de elementos;
• n_items – Nº de elementos a ordenar;
• size – Dimensão (em bytes) de cada elemento no array;
• compareFunction – Função que compara dois (quaisquer) elementos do array.

    Usamos sizeof(TagData) e não sizeof(StoreArr), pois
    queremos ordenar o array data que esta dentro de arr associado a estrutura TagData, daí essa implementação
*/
}


/*Escreva a função de comparação de nome trackComp, destinada a ser usada pelas funções
das alíneas anteriores, que origine a ordenação do array de tags pertencente a um descritor do
tipo StoreArr por ordem crescente do membro track das tags. Considere a definição
incompleta da função como apresentada na linha 2 da caixa com troço de código.
*/
int trackComp(const void *e1, const void *e2){

    const TagData *tag1 = (const TagData*)e1;
    const TagData *tag2 = (const TagData*)e2;

    return (tag1->track-tag2->track);

}

/*que insere no array de tags pertencente ao descritor indicado por arr uma nova tag, indicada
pelo parâmetro tag. A função admite que o array está ordenado pelo critério da respetiva função
comp e tem de mantê-lo ordenado pelo mesmo critério, devendo retornar 1 se a inserção for bem
sucedida e 0 se não for bem sucedida (por não haver espaço disponível no array), caso em que
não deverá alterar nada no array pertencente ao descritor indicado por arr. A função não pode
usar funções auxiliares de ordenação, como a função qsort da biblioteca normalizada. 
*/
int insertOrd(StoreArr *arr, TagData *tag)
{
    if(arr->count == arr->space)
        return 0;
    else
    {
        int i;

        for(i = arr->count-1; i >= 0 && (arr->comp(&arr->data[i], tag) > 0); i--)
        {
            arr->data[i+1] = arr->data[i];
        }
        arr->data[i+1] = *tag;
        arr->count++;
    }
return 1;
}
//Wtf is that bro