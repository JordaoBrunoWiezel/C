CC - gcc
CFLAGS - g -Wall -lm

prog: prog.o comp1.o comp2.o data.o info.o
	$(CC) $(CFLAGS) prog.o comp1.o comp2.o data.o info.o

prog.o: prog.c comp1.h comp2.h data.h info.h types.h // nao sei se é todos
	$(CC) $(CFLAGS) prog.c

comp1.o: comp1.c comp1.h typesh
	$(CC) $(CFLAGS) types.c

comp2.o: comp2.c comp2.h types.h
	$(CC) $(CFLAGS) comp2.c

data.o: data.c data.h comp1.h info.h types.h
	$(CC) $(CFLAGS) data.c

info.o: info.c info.h types.h
	$(CC) $(CFLAGS) info.c

clena:
	rm -f *.o prog