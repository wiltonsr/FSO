#------------------------------------------------------------------------------
# Project's name
#------------------------------------------------------------------------------
PROGRAM = prime_q01b

#------------------------------------------------------------------------------
# Directories
#------------------------------------------------------------------------------
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib

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
INCLUDE = -Iheaders/
CFLAGS = -std=c11 -lm $(INCLUDE)
SOFLAGS = -fPIC
SOFLAGS2 = -shared -fPIC
SHAREDO = libprimo.so
LIBRARY = -lprimo
LIBFLAGS = -Wl,-rpath,./lib -lm

#------------------------------------------------------------------------------
# Executable's name
#------------------------------------------------------------------------------
EXECUTABLE = run

#------------------------------------------------------------------------------
# To execute recipes regardless of whether there is files named
#------------------------------------------------------------------------------
.PHONY: clean directories

all: directories $(PROGRAM)

$(PROGRAM): $(SOURCE)
	@echo "Initing compilation..."
	@echo "Compile source files"
	$(CC) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o $(CFLAGS)
	$(CC) -c $(SOFLAGS) $(SRC_DIR)/libprimo.c -o $(OBJ_DIR)/libprimo.o $(CFLAGS)
	@echo "Creating shared object"
	$(CC) $(SOFLAGS2) -o $(LIB_DIR)/$(SHAREDO) $(OBJ_DIR)/libprimo.o
	@echo "Compile objects to main"
	$(CC) -o $(BIN_DIR)/$(PROGRAM) $(OBJ_DIR)/main.o -L./$(LIB_DIR) $(LIBRARY) $(LIBFLAGS) $(CFLAGS)
	@echo "Creating link to run"
	$(LINK_FORCE) $(BIN_DIR)/$(PROGRAM) $(EXECUTABLE)
	@echo "Done!"

directories:
	@$(MKDIR_P) $(OBJ_DIR)
	@$(MKDIR_P) $(BIN_DIR)
	@$(MKDIR_P) $(LIB_DIR)

clean:
	@echo "Excluding..."
	@echo "Clean executables..."
	rm -f $(PROGRAM)
	rm -f $(EXECUTABLE)
	rm -rf $(BIN_DIR)
	@echo "Clean objects..."
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	rm -rf $(LIB_DIR)
	rm -rf *.o
	@echo "Ready exclusion!"
