#!/bin/bash


# Check if a project name was provided as the first argument
if [ -z "$1" ]; then
  echo "Usage: $0 <project_name>"
  exit 1
fi

# Define the project name
PROJECT_NAME=$1
# Create project directory structure

mkdir -p "$PROJECT_NAME/src" "$PROJECT_NAME/include" "$PROJECT_NAME/build"

# Create a basic main.cpp file in src
cat <<EOL > "$PROJECT_NAME/src/main.cpp"
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
EOL


# Create a Makefile in the project root
cat <<EOL > "$PROJECT_NAME/Makefile"
# Compiler and flags
CC = g++
CFLAGS = -Iinclude -Wall -g

# Project structure
SRCDIR = src
BUILDDIR = build
TARGET = \$(BUILDDIR)/$PROJECT_NAME

# Find all .cpp files in src directory
SRCFILES := \$(wildcard \$(SRCDIR)/*.cpp)

# Define object files
OBJFILES := \$(SRCFILES:\$(SRCDIR)/%.cpp=\$(BUILDDIR)/%.o)

# Default target
all: \$(TARGET)

# Rule to build the target
\$(TARGET): \$(OBJFILES)
	\$(CC) \$(CFLAGS) -o \$@ \$^

# Rule to compile source files into object files
\$(BUILDDIR)/%.o: \$(SRCDIR)/%.cpp | \$(BUILDDIR)
	\$(CC) \$(CFLAGS) -c -o \$@ \$<

# Create build directory if it does not exist
\$(BUILDDIR):
	mkdir -p \$(BUILDDIR)

# Clean the build directory
clean:
	rm -rf \$(BUILDDIR)/*.o \$(TARGET)

.PHONY: all clean
EOL

echo "Project '$PROJECT_NAME' created successfully."