CC = gcc
BINARY = ./nqueens

all: clean compile clear run

run:
	# run and test input file
	$(BINARY)

clean:
	rm *.o

clear:
	clear

compile: nqueens.o
	$(CC) -pg -o $(BINARY) nqueens.o

nqueens.o:
	# Ultra fast compilation
	$(CC) -c -pg -O3 ./nqueens.c
