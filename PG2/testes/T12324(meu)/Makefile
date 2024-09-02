CC = - g
CFLAGS = - g -Wall -lm

test: test.o minArr.o min2.o
	$(CC) $(CFLAGS) -o test.o minArr.o min2.o

test.o: test.c minArr.h
	$(CC) $(CFLAGS) -c test.c -o test.o

min2.o: min2.c min2.h
	$(CC) $(CFLAGS) -c min2.c -o min2.o

minArr.o: minArr.c minArr.h min2.h
	$(CC) $(CFLAGS) -c minArr.c -o minArr.o

clean:
	rm -f *.o test