PROGRAM = triangle_calculator
SOURCE = main.c
CC = gcc

all: $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(CC) -c main.c -o main.o
	$(CC) main.o -o $(PROGRAM)

clean:
	rm -f $(PROGRAM)
	rm -f *.o
