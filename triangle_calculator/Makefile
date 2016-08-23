#------------------------------------------------------------------------------
# Project's name
#------------------------------------------------------------------------------
PROGRAM = triangle_calculator

#------------------------------------------------------------------------------
# Directories
#------------------------------------------------------------------------------
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

#------------------------------------------------------------------------------
# All source and objects files
#------------------------------------------------------------------------------
SOURCE = ${wildcard $(SRC_DIR)/*.c}
OBJ = ${addprefix $(OBJ_DIR)/, ${notdir ${SOURCE:.c=.o}}}

#------------------------------------------------------------------------------
# Alias to commands
#------------------------------------------------------------------------------
MKDIR_P = mkdir -p
LINK_FORCE = ln -fn

#------------------------------------------------------------------------------
# Compilator and flags
#------------------------------------------------------------------------------
CC = gcc
INCLUDE = -Iinclude/
CFLAGS = -lm -std=c11 $(INCLUDE)

#------------------------------------------------------------------------------
# Executable's name
#------------------------------------------------------------------------------
EXECUTABLE = run

.PHONY: clean directories

all: directories $(PROGRAM)

$(PROGRAM): $(SOURCE)
	@echo $(OBJ)
	$(CC) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o $(CFLAGS)
	$(CC) -c $(SRC_DIR)/io.c -o $(OBJ_DIR)/io.o $(CFLAGS)
	$(CC) -c $(SRC_DIR)/operations.c -o $(OBJ_DIR)/operations.o $(CFLAGS)
	$(CC)  $(OBJ) -o $(BIN_DIR)/$(PROGRAM) $(CFLAGS)
	$(LINK_FORCE) $(BIN_DIR)/$(PROGRAM) $(EXECUTABLE)

directories:
	@$(MKDIR_P) $(OBJ_DIR)
	@$(MKDIR_P) $(BIN_DIR)

clean:
	rm -f $(PROGRAM)
	rm -f $(EXECUTABLE)
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf *.o
