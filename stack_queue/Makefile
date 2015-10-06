#using gcc compiler
CC = gcc

#output path and filename
BINARY = ./build/stack

#sources directory
SRC = src/stack.c src/main.c 

#includes directory
INCLUDES = ./includes

#libraries and flags
LIBS = -lm
FLAGS = -g

all: compile run

compile:
	$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC) $(LIBS)

run:
	$(BINARY)

clean:
	rm *.o