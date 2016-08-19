SRC_DIR = src/
OBJ_DIR = obj/
BIN_DIR = bin/
SOURCE = $(SRC_DIR)main.c
PROGRAM = sorting_integers
MKDIR_P = mkdir -p
MOVE_FILE = mv
CFLAGS = -std=c11
CC = gcc

.PHONY: clean directories

all: directories $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(CC) -c $(SRC_DIR)main.c -o $(OBJ_DIR)main.o
	$(CC) $(OBJ_DIR)* -o $(BIN_DIR)$(PROGRAM) $(CFLAGS)

directories:
	$(MKDIR_P) $(OBJ_DIR)
	$(MKDIR_P) $(BIN_DIR)

clean:
	rm -f $(PROGRAM)
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf *.o
