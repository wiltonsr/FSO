PROGRAM = triangle_calculator
SOURCE = main.c io.c operations.c
CC = gcc

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(CC) -c main.c -o main.o
	$(CC) -c io.c -o io.o
	$(CC) -c operations.c -o operations.o
	$(CC) main.o io.o operations.o -o $(PROGRAM)

clean:
	rm -f $(PROGRAM)
	rm -f *.o
