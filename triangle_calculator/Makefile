PROGRAM = triangle_calculator
SOURCE = main.c io.c operations.c
CC = gcc
CFLAGS = -lm -std=c11

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(CC) -c main.c -o main.o
	$(CC) -c io.c -o io.o $(CFLAGS)
	$(CC) -c operations.c -o operations.o
	$(CC) main.o io.o operations.o -o $(PROGRAM) $(CFLAGS)

clean:
	rm -f $(PROGRAM)
	rm -f *.o
