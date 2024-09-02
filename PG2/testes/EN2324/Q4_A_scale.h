#ifndef __SCALE_H__
#define __SCALE_H__

#include "rectangle.h"

void scale (Rectangle * r, double factor);

#endif

/* O header file "scale.h" deve ser incluida nos modulos de código fonte (.c) onde a função "scale" é chamada ou utilizada.
No caso, o arquivo "scale.h" deve ser incluido no arquivo "aplic.c", pois é onde a função "scale" é chamada no main e no
scale.c para garantir a consistência entre a declaração e a definição da função "scale".

A função "multiply" não precisa ser declarada no arquivo "scale.h" porque não é chamada diretamente pela função "main" ou
por qualquer outra função fora do módulo onde está definida (scale.c). A função multiply é marcada com um símbolo t minúsculo 
(t multiply), indicando que ela tem ligação interna (ou seja, é uma função estática) no módulo scale.o. Funções com ligação 
interna são visíveis apenas dentro do arquivo fonte em que são definidas e não devem ser acessadas ou chamadas por outros módulos.

O objetivo do header file é fornecer deeclarações das funções que podem ser usados por outros módulos :)
*/