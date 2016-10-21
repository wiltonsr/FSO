#------------------------------------------------------------------------------
# Project's name
#------------------------------------------------------------------------------
PROGRAM = run

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
CFLAGS = -O2 -std=c11 $(INCLUDE) -lpthread

#------------------------------------------------------------------------------
# Executable's name
#------------------------------------------------------------------------------
EXECUTABLE = run

.PHONY: clean directories

all: directories $(PROGRAM)

$(PROGRAM): $(SOURCE)
	@echo "Initing compilation..."
	@echo "Compile source files"
	$(CC) -c $(SRC_DIR)/buscador.c -o $(OBJ_DIR)/buscador.o $(CFLAGS)
	$(CC) -c $(SRC_DIR)/file.c -o $(OBJ_DIR)/file.o $(CFLAGS)
	@echo "Compile objects to main"
	$(CC)  obj/buscador.o -o $(BIN_DIR)/buscador $(CFLAGS)
	$(CC)  obj/file.o -o $(BIN_DIR)/file $(CFLAGS)
	@echo "Creating link to run"
	$(LINK_FORCE) $(BIN_DIR)/buscador buscador
	$(LINK_FORCE) $(BIN_DIR)/file file
	@echo "Done!"

directories:
	@$(MKDIR_P) $(OBJ_DIR)
	@$(MKDIR_P) $(BIN_DIR)

clean:
	@echo "Excluding..."
	@echo "Clean executables..."
	rm -f $(PROGRAM)
	rm -f $(EXECUTABLE)
	rm -rf $(BIN_DIR)
	@echo "Clean objects..."
	rm -f $(OBJ)
	rm -f file buscador
	rm -rf $(OBJ_DIR)
	rm -rf *.o
	@echo "Ready exclusion!"
