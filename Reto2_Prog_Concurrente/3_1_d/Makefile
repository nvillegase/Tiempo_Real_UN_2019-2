CC=gcc
CFLAGS=-Wall

all: main1 main2

main1: main1.o 
	gcc -pthread -o main1 main1.o

main2: main2.o
	gcc -pthread -o main2 main2.o

main1.o: 3_1_d_1.c
	gcc -pthread -c 3_1_d_1.c -o main1.o

main2.o: 3_1_d_2.c
	gcc -pthread -c 3_1_d_2.c -o main2.o

clean:
	rm -f main1 main2 main1.o main2.o