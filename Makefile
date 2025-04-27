# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Folders
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Target executable
TARGET = $(BIN_DIR)/game

# Default build type
BUILD_TYPE ?= Release

ifeq ($(BUILD_TYPE), Debug)
CXXFLAGS += -g
else ifeq ($(BUILD_TYPE), Release)
CXXFLAGS += -O2
endif

# Find all source files recursively
SOURCES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compiling
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create folders
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Run shortcut: Build and run the game
run: all
	@echo "Starting the game..."
	@$(TARGET)

# Aliases
debug:
	$(MAKE) BUILD_TYPE=Debug

release:
	$(MAKE) BUILD_TYPE=Release

# Clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean debug release run
