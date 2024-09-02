

// NÃO ESTA DANDO CERTO

#include <stdio.h>
#include <stdbool.h>

int count_consecutive(int vals[], int idx, int dim) {
    int contador = 0;

    if (idx < 0 || idx >= dim) {
        printf("indice invalido.\n");
        return -1;
    }

    int valor_alvo = vals[idx];

    for (int i = idx; i < dim; i++) {
        if(vals[i] == valor_alvo) {
        contador++;
        }
    }

    return contador;
}

bool has_elements_consecutive(int v[], int dim, int value, int n_elems, int *first){

    for (int i= 0; i<dim; i++){
        if(v[i] == value){
            *first = i;
            int count = count_consecutive(v, *first, dim);
                if (count == n_elems) {
                    return true;
            }
        }
    }
return false;
}


int main(){
    int dim = 11;
    int value = 0;
    int n_elems = 3;
    int first = 0;
    int a[11] = {1,1,1,0,0,0,1,1,0,0,0};

    bool b = has_elements_consecutive(a, dim, value, n_elems, &first);

    if( b ){ 
    printf("Subsequencia de %d's com inicio em %d e de dimensao %d\n",value,first,n_elems);
    } else {
        printf("Nenhuma subsequencia encontrada.\n");
    }



}