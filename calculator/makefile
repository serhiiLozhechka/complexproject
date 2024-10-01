CC = gcc
CFLAGS = -Iinclude
LDFLAGS = -Llib
LIBS = -lcalc -lm  # Link both libcalc and the math library

SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib

# Default Target
all: $(BIN_DIR)/calc  # Default target to build the executable

# Create necessary directories before building
$(BIN_DIR) $(LIB_DIR):
	@mkdir -p $@

# Target to build the static library
lib/libcalc.a: $(SRC_DIR)/calc.o | $(LIB_DIR)
	@mkdir -p lib
	ar rcs lib/libcalc.a $(SRC_DIR)/calc.o

# Target to compile calc.o
$(SRC_DIR)/calc.o: $(SRC_DIR)/calc.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/calc.c -o $(SRC_DIR)/calc.o

# Target to build the executable
$(BIN_DIR)/calc: $(SRC_DIR)/main.c lib/libcalc.a | $(BIN_DIR) 
	@mkdir -p bin
	$(CC) $(SRC_DIR)/main.c -o $(BIN_DIR)/calc $(LDFLAGS) $(LIBS)

# Clean target
clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(BIN_DIR)/*
	rm -f $(LIB_DIR)/*
