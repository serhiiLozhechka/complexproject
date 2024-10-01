# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -fPIC
LDFLAGS = -Llib
LIBS = -lconvert

# Directories
SRC_DIR = src
BIN_DIR = bin
LIB_DIR = lib
OBJ_DIR = obj

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Default target: Build both the uppercase and lowercase programs
all: $(BIN_DIR)/uper $(BIN_DIR)/low | lib/libconvert.so

# Create necessary directories before building
$(BIN_DIR) $(LIB_DIR) $(OBJ_DIR):
	@mkdir -p $@

# Explicit rule for each source file (loop approach)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) -c $< -o $@

# Build shared library - now depending only on convert.o
lib/libconvert.so: $(OBJ_DIR)/convert.o | $(LIB_DIR)
	$(CC) -shared -o $@ $^

# Build the uppercase program (uper)
$(BIN_DIR)/uper: $(SRC_DIR)/uper.c lib/libconvert.so | $(BIN_DIR)
	$(CC) $(SRC_DIR)/uper.c -o $@ $(LDFLAGS) $(LIBS)

# Build the lowercase program (low)
$(BIN_DIR)/low: $(SRC_DIR)/low.c lib/libconvert.so | $(BIN_DIR)
	$(CC) $(SRC_DIR)/low.c -o $@ $(LDFLAGS) $(LIBS)

# Install the shared library and binaries
install: lib/libconvert.so $(BIN_DIR)/uper $(BIN_DIR)/low
	sudo cp $(LIB_DIR)/libconvert.so /usr/local/lib/
	sudo cp $(BIN_DIR)/uper /usr/local/bin/
	sudo cp $(BIN_DIR)/low /usr/local/bin/
	sudo ldconfig
	@echo "Programs and library installed successfully."

# Uninstall the shared library and binaries
uninstall:
	sudo rm -f /usr/local/lib/libconvert.so
	sudo rm -f /usr/local/bin/uper
	sudo rm -f /usr/local/bin/low
	sudo ldconfig
	@echo "Programs and library uninstalled successfully."

# Clean up generated files
clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/*
	rm -f $(LIB_DIR)/*

clean-all:
	rm -rf $(OBJ_DIR)/
	rm -rf $(BIN_DIR)/
	rm -rf $(LIB_DIR)/

# List available targets
list:
	@echo "Available targets:"
	@echo "  all        - Build both the uppercase and lowercase programs and shared library"
	@echo "  install    - Install the shared library and programs"
	@echo "  uninstall  - Uninstall the shared library and programs"
	@echo "  clean      - Remove all compiled files"
	@echo "  clean-all  - Remove all local temp folders"
	@echo "  list       - Show this list of targets"

# Phony targets
.PHONY: all install uninstall clean clean-all list
