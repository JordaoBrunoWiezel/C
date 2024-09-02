/*
Apresente a lista de símbolos produzida por “nm test.o” e a respetiva classificação (t, T,
U, etc.). Para cada símbolo indefinido, indique qual o módulo que o resolve ou se é resolvido
pela biblioteca normalizada.

A.
0000000000000000 T main
                 U comp1    Resolvido por comp1.o -> comp1 é uma função pública definida em comp1.o.
                 U sortInt  Resolvido por sortint.o -> sortInt é uma função pública definida em sortint.o.
                 U scanf    Resolvido pela biblioteca padrão (libc)
                 U printf   Resolvido pela biblioteca padrão (libc)
                 U putchar  Resolvido pela biblioteca padrão (libc)

T -> Simbolo Publico de texto(T) que representa a função 'main' do programa
U -> Indefinidos: São referenciados no arquivo test.o, mas não são definidos dentro dele
*/

/* 
1. Sim, a função select no módulo sortint.o tem o atributo static.
2. A função comp2 no módulo comp2.o poderia potencialmente ser static se não for utilizada fora deste módulo. 
Para decidir isso com certeza, precisaríamos de mais informações sobre como comp2 é utilizada. 
Se comp2 for usada apenas dentro de comp2.o, adicionar static pode ser uma boa prática para limitar o escopo de visibilidade da função.

"Funções estaticas, o atributo static limita o escopo da função ao arquivo onde ela é definida"
*/

