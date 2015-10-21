# >> COMPIILER
CC = gcc

# >> OUTPUT
BINARY = ./build/

# >> .c SOURCES
SRC = src/ src/

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
