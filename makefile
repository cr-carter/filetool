# Program name
PROGRAM = filetool

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wpedantic -Waggregate-return -Wwrite-strings -Wvla -Wfloat-equal -std=c99

# Directories
SRC_DIR = src
BUILD_DIR = build
BINARY_DIR = bin
DATA_DIR = data

# Executable name
TARGET = $(PROGRAM)

# Find all source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Create object file paths
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Default target
all: $(TARGET)

debug: CFLAGS += -ggdb -O0 -DDEBUG
debug: rebuild

# Create directories
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(DATA_DIR):
	mkdir -p $(DATA_DIR)

# Create executable
$(TARGET): $(OBJ_FILES) | $(BUILD_DIR) $(DATA_DIR)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(TARGET)

# Compile .c to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) $(TARGET)


rebuild: clean all
