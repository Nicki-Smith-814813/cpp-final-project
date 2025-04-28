# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Folders
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# Targets
TARGET = $(BIN_DIR)/game
AUTOSAVE_TARGET = $(BIN_DIR)/autosave_game

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

# Linking normal game
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Linking autosave game
$(AUTOSAVE_TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -DAUTOSAVE -o $@ $^

# Compiling .cpp to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create folders
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Run normal
run: $(TARGET)
	@echo "Starting the game..."
	@./$(TARGET)

# Run autosave
autosave: $(AUTOSAVE_TARGET)
	@echo "Starting the autosave-enabled game..."
	@./$(AUTOSAVE_TARGET)

# Aliases
debug:
	$(MAKE) BUILD_TYPE=Debug

release:
	$(MAKE) BUILD_TYPE=Release

# Clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean debug release run autosave
