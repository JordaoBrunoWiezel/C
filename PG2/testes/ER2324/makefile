CC = - gcc
CFlags = - g - Wall - lm

main: main.o base.o volume.o
	$(CC) $(CFLAGS) -o main.o base.o volume.o

main.o: main.c volume.h solid.h
	$(CC) $(CFLAGS) -c main.c

base.o: base.c base.h solid.h
	$(CC) $(CFLAGS) -c base.c

volume.o: volume.c volume.h base.h solid.h
	$(CC) $(CFLAGS) -c volume.c

clean:
	rm -f *.o main