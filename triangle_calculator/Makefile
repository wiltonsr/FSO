SRC_DIR = src/
OBJ_DIR = obj/
BIN_DIR = bin/
SOURCE = $(SRC_DIR)main.c $(SRC_DIR)io.c $(SRC_DIR)operations.c
PROGRAM = triangle_calculator
MKDIR_P = mkdir -p
MOVE_FILE = mv
CFLAGS = -lm -std=c11
CC = gcc

.PHONY: clean directories

all: directories $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(CC) -c $(SRC_DIR)main.c -o $(OBJ_DIR)main.o
	$(CC) -c $(SRC_DIR)io.c -o $(OBJ_DIR)io.o $(CFLAGS)
	$(CC) -c $(SRC_DIR)operations.c -o $(OBJ_DIR)operations.o $(CFLAGS)
	$(CC) $(OBJ_DIR)* -o $(BIN_DIR)$(PROGRAM) $(CFLAGS)

directories:
	$(MKDIR_P) $(OBJ_DIR)
	$(MKDIR_P) $(BIN_DIR)

clean:
	rm -f $(PROGRAM)
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf *.o
