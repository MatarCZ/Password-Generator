# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

# Target executable
TARGET := PWGen.exe

# Source file
SRC := pass.cpp

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Rule to run the target
run: $(TARGET)
	./$(TARGET)

# Clean up generated files
clean:
	rm -f $(TARGET)

.PHONY: all run clean