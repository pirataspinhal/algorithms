# >> COMPIILER
CC = gcc

# >> OUTPUT
BINARY = ./build/heap

# >> .c SOURCES
SRC = src/heap.c src/main.c 

# >> .h INCLUDES
INCLUDES = ./includes

# >> OPTIONS
# LIBRARIES
LIBS = -lm
#FLAGS
FLAGS = -g

# >> COMMANDS
all: compile run

compile:
	$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC) $(LIBS)

run:
	$(BINARY)

clean:
	rm *.o