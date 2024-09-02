/*
Considerando a execução dos comandos «gcc -c *.c» e «nm *.c», apresente a lista de
símbolos de todos os módulos compilados, e a respetiva classificação com a convenção da
ferramenta nm (p. ex.: T, public text; t, private text; U, undefined).
Indique ainda, por cada símbolo com classificação U, se é resolvido pela biblioteca normalizada
ou por algum dos outros módulos, e, neste caso, qual deles. 



Aqui está uma possível lista de símbolos para cada módulo compilado, considerando a convenção da ferramenta nm:

base.o:

0000000000000000 T base
                 U Solid

volume.o:

0000000000000010 t area
0000000000000000 T volume
                 U base
                 U Solid

main.o:

0000000000000000 T main
                 U scanf
                 U printf
                 U volume
                 U Solid

OBS:
T-> Texto Publico: Esses simbolos que sao visiveis e acessiveis fora do arquivo objeto ou executavel. Eles são geralmente funções ou variaveis
globais que podem ser utilizadas por outros módulos. 
t -> Texto privado: Esses simbolos são visiveis apenas internamente dentro do arquivo objeto ou executavel. Eles são geralmente funções ou variaveis
estaticas que não podem ser acessadas de fora do arquivo (ex: area).
U -> Indefinido: Isso indica que o simbolo é referenciado no arquivo objeto, mas não definido nele. Ele espera que o simbolo seja definido em
outro lugar, como outro arquivo objeto ou uma biblioteca partilhada. 


Agora, para cada símbolo com classificação U:

Solid é definido no header file solid.h.
base é definido no módulo base.c.
volume é definido no módulo volume.c.
printf e scanf são resolvidos pela biblioteca padrão C.
*/