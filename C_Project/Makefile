
	
# Define the compiler and flags
CC = gcc
CFLAGS = -O2 -Wall
LDFLAGS = -ldl -D_GNU_SOURCE

# Targets and their dependencies
all: example arcfour

# Link example executable
example: example.o arcfour.o
	$(CC) $(CFLAGS) -o $@ example.o arcfour.o $(LDFLAGS)

# Compile example.c into example.o
example.o: example.c arcfour.h
	$(CC) $(CFLAGS) -c example.c

# Link arcfour shared library
arcfour: arcfour.o
	$(CC) $(CFLAGS) -shared -o libarcfour.so arcfour.o $(LDFLAGS)

# Compile arcfour.c into arcfour.o
arcfour.o: arcfour.c arcfour.h
	$(CC) $(CFLAGS) -fPIC -c arcfour.c

# Clean up generated files
clean:
	rm -f *.o *.so example

# Install shared library to standard location
install:
	cp libarcfour.so /usr/local/lib/
	ldconfig

