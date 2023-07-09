CC=gcc
CFLAGS=-Wall -g -O0 -fno-stack-protector

chamber: chamber.o
	$(CC) -o chamber chamber.o

.PHONY: clean

clean:
	rm -f *.o chamber
