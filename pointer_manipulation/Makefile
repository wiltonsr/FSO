SRC_DIR = src/
OBJ_DIR = obj/
BIN_DIR = bin/
SOURCE = $(SRC_DIR)main.c
PROGRAM = pointer_manipulation
EXECUTABLE = run
MKDIR_P = mkdir -p
LINK_FORCE = ln -fn
MOVE_FILE = mv
CFLAGS = -lm -std=c11
CC = gcc

.PHONY: clean directories link

all: directories $(PROGRAM)

$(PROGRAM): $(SOURCE)
	$(CC) -c $(SRC_DIR)main.c -o $(OBJ_DIR)main.o
	$(CC) $(OBJ_DIR)* -o $(BIN_DIR)$(PROGRAM) $(CFLAGS)
	$(LINK_FORCE) $(BIN_DIR)$(PROGRAM) $(EXECUTABLE)

directories:
	$(MKDIR_P) $(OBJ_DIR)
	$(MKDIR_P) $(BIN_DIR)

clean:
	rm -f $(PROGRAM)
	rm -f $(EXECUTABLE)
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf *.o
