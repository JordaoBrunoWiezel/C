CC - gcc
CFLAGS - g -Wall -lm

main: main.o ratio.o area.o height.o width.o
	$(CC) $(CFLAGS) -o main.o ratio.o area.o height.o width.o

main.o: main.c area.h retangle.h
	$(CC) $(CFLAGS) -c main.c 

ratio.o: ratio.c ratio.h width.h height.h retangle.h
	$(CC) $(CFLAGS) -c ratio.c

area.o: ratio.c ratio.h width.h height.h retangle.h
	$(CC) $(CFLAGS) -c area.c

height.o: height.c height.h retangle.h
	$(CC) $(CFLAGS) -c height.c

width.o: width.c width.h retangle.height
	$(CC) $(CFLAGS) -c width.c

clean:
	rm -f *.o main