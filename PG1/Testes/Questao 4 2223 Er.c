#include <stdio.h>
#include <stdbool.h>

int count_consecutive(int vals[], int dim, int idx){

    int seq1 = 0;
    int n = vals[idx];

    for(int i = idx; i < dim; i++){
        if(vals[i] == n){
            seq1++;
                if(vals[i] != vals[i+1]){
                    break;
                }
        }
    }
return seq1;
}

bool has_elements_consecutive (int v[], int dim, int value, int n_elements, int *first){

    for(int i= 0; i < dim; i++){
        if(v[i] == value){
            *first = i;
                if(count_consecutive(v, dim, i) >= n_elements){
                    return true;
                }
        }
    }
return false;
}

int main(){
    int a[11]={1,1,1,0,0,0,1,1,0,0,0};
    int dim=11;
    int value=0;
    int n_elems=3;
    int first=0;

bool b = has_elements_consecutive (a, dim, value, n_elems, &first);

    if( b ) {
        printf("Subsequencia de %d's com inicio em %d e de dimensao %d\n",value,first,n_elems);
    }

}