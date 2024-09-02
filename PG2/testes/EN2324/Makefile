CC = gcc
CFLAGS = -g -Wall

aplic: aplic.o scale.o area.o width.o height.o ratio.o rectangle.o
$(CC) $(CFLAGS) -o aplic.o scale.o area.o width.o height.o ratio.o rectangle.o -lm

aplic.o: aplic.c rectangle.h scale.h area.h 
$(CC) $(CFLAGS) -c aplic.c

scale.o: scale.c scale.h rectangle.h
$(CC) $(CFLAGS) -c scale.c

area.o: area.c area.h height.h width.h rectangle.h
$(CC) $(CFLAGS) -c area.c

height.o: height.c height.h rectangle.h
$(CC) $(CFLAGS) -c height.c

ratio.o: ratio.c ratio.h rectangle.h width.h height.h
$(CC) $(CFLAGS) -c ratio.c

width.o: width.c width.h rectangle.h
$(CC) $(CFLAGS) -c width.c

rectangle.o: rectangle.c rectangle.h
$(CC) $(CFLAGS) -c rectangle.c

clean:
	rm -f *.o aplic