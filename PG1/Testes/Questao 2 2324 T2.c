#include <stdio.h>
#include <stdbool.h>

typedef struct set {
int elems[MAX_SET];
int size; // dimensão do set
} set_t;

bool random_subset(set_t *src_set, set_t *dst_set, int dst_size){

    int indice;

    if (src_set->size < dst_size) {
            return false;  // Não há elementos suficientes para criar o conjunto
    } else {

        for(int i=0; i < src_set->size; i++){

            indice = random_range(0, src_set->size-1);

            dst_set->elems[i] = src_set->elems[indice];
        
            srt_set->elems[indice] = srt_set->elems[src_set->size-1];

            src_set->size--;

        }

    } 
return true;
}