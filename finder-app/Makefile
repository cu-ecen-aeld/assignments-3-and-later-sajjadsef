# Makefile for a C program with cross-compilation support

# Cross-compiler and flags for the target architecture
CROSS_CFLAGS = -Wall -Wextra -std=c11

# Source files and executable name
SRC = writer.c
EXEC = writer

# Default target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(SRC)
	$(CROSS_COMPILE)gcc $(CROSS_CFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(EXEC)

# Phony target to prevent conflicts with file names
.PHONY: all clean
