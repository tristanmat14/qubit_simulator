# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -pedantic -std=c++17 -Iinclude -Isrc/classes
CC := gcc
CFLAGS := -Iinclude

# Linking flags
LDFLAGS := -Llib -Llib/GLFW -lglfw3 -lGL -lX11 -lXrandr -lpthread -ldl

# Source Files
SRC_CXX := $(shell find src -name "*.cpp")
SRC_C := $(shell find src -name "*.c")

# Object Files
OBJ_CXX := $(SRC_CXX:src/%.cpp=build/%.o)
OBJ_C := $(SRC_C:src/%.c=build/%.o)

OBJS := $(OBJ_CXX) $(OBJ_C)

TARGET := build/app.exe

# Build rules
all: create_build_dir $(TARGET)

# Create build dir before compilation
create_build_dir:
	mkdir -p build

# Rule for linking object files together into the target executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile C++ source files to object files
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/%.o: src/classes/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile C source files to object files
build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean: 
	rm -rf build

