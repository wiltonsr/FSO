#------------------------------------------------------------------------------
# Project's name
#------------------------------------------------------------------------------
PROGRAM = finding_max

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
CFLAGS = -lm -O2 -Wall -std=c11 $(INCLUDE) -ftrapv -Wextra -Wfloat-equal -Wundef -Winit-self -Wpointer-arith -Wpointer-arith

#------------------------------------------------------------------------------
# Executable's name
#------------------------------------------------------------------------------
EXECUTABLE = run

.PHONY: clean directories

all: directories $(PROGRAM)

$(PROGRAM): $(SOURCE)
	# @echo "Initing compilation..."
	# @echo "Compile source files"
	# $(CC) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o $(CFLAGS)
	# $(CC) -c $(SRC_DIR)/io.c -o $(OBJ_DIR)/io.o $(CFLAGS)
	# $(CC) -c $(SRC_DIR)/operations.c -o $(OBJ_DIR)/operations.o $(CFLAGS)
	# @echo "Compile objects to main"
	# $(CC)  $(OBJ) -o $(BIN_DIR)/$(PROGRAM) $(CFLAGS)
	# @echo "Creating link to run"
	# $(LINK_FORCE) $(BIN_DIR)/$(PROGRAM) $(EXECUTABLE)
	# @echo "Done!"

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
	rm -rf $(OBJ_DIR)
	rm -rf *.o
	@echo "Ready exclusion!"
