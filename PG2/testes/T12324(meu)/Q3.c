/*
A.
Stadart output:
-1 7 2 -2 6 11
r=3
4 8 12 -2 6 11

A função f1 percorre um array de origem, verifica cada elemento com a função (f2) (Verifica se é Par)
e copia os elementos que satisfazem a condição para o array de destino. Ela retorna o número de elementos copiados. 
*/

/*
B.
A função f1 pode não funcionar corretamente se os arrays s(a) e t(b) tiverem diferentes número de elementos

Se o array t(b) for maior que s(a), a função f1 funcionará corretamente. Após copiar todos os elementos que satisfazem a 
condição de s(a) para t(b), o restante do array t(b) permanecerá inalterado.

Se o array t(b) for menor que s(a), há o risco de a função f1 sobrescrever memória além dos limites de t(b), resultando 
em comportamento indefinido.  Isso acontece porque o ponteiro a continua a ser incrementado e elementos continuam a ser 
copiados para além do fim de t(b)
*/

/*
C.
Problemas com NULL como Destino
Quando t é NULL, o ponteiro 'a'(t=b) também é NULL. Então, a linha *a(b) = *f(a); dentro do loop for causaria um 
comportamento indefinido (tentativa de desreferenciar um ponteiro nulo).
Para tornar isso viável, precisaríamos modificar f1 para evitar a cópia se t for NULL, e apenas incrementar o ponteiro f. Em vez de copiar os valores, a função f1 chamaria uma função como f3 para imprimir os valores.
*/