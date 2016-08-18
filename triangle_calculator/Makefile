PROGRAM = triangle_calculator
SOURCE = main.c io.c
CC = gcc

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(CC) -c main.c -o main.o
	$(CC) -c io.c -o io.o
	$(CC) main.o io.o -o $(PROGRAM)

clean:
	rm -f $(PROGRAM)
	rm -f *.o
