CC = - gcc
CFLAGS = - g -Wall -lm

test: test.o comp1.o comp2.o sortint.o swap.o
	$(CC) $(CFLAGS) -o test.o comp1.o comp2.o sortint.o swap.o

test.o: test.c comp1.h sortint.h
	$(CC) $(CFLAGS) -c test.c

comp1.o: comp1.c comp1.h 
	$(CC) $(CFLAGS) -c comp1.c

comp2.o: comp2.c comp2.h comp1.h
	$(CC) $(CFLAGS) -c comp2.c

sortint.o: sortint.c sortint.h swap.h
	$(CC) $(CFLAGS) -c swap.c

swap.o: swap.c swap.h
	$(CC) $(CFLAGS) -c test.c

clean:
	rm -f *.o test