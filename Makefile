CC=gcc
CFLAGS=-Wall

main: main.o marcapasos.o

clean:
	rm -f main main.o marcapasos.o