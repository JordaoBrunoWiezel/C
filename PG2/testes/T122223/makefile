CC = - gcc
CFLAGS = - g -Wall -lm

myaplic: myaplic.o m1.o m2.o 
	$(CC) $(CFLAGS) -o myaplic.o m1.o m2.o

myaplic.o: myaplic.c m1.h
	$(CC) $(CFLAGS) -c myaplic.c

m1.o: m1.c m1.h m2.h
	$(CC) $(CFLAGS) -c m1.c

m2.o: m2.c m2.h
	$(CC) $(CFLAGS) -c m2.c

clean:
	rm -f *.o test

/* Dado que myaplic.c utiliza diretamente apenas a função f1, ele deve incluir apenas o arquivo de cabeçalho m1.h.
   necessário incluir m3.c no Makefile se nenhuma função de m3.c é usada diretamente ou indiretamente por myaplic.c
*/