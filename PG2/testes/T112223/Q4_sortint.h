#ifndef __SORTINT_H__
#define __SORTINT_H__

#include <swap.h>

void sortInt(int *a, int size, int (*comp) (int *, int *));

#endif

/* O arquivo 'sortint.h' deve ser incluido nos módulos de código fonte (.c) onde a função "sortin" é utilizada. Neste caso
deve ser incluida nos seguintes arquivos fontes:
1. sortint.c
2. main.c
*/