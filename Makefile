CC = gcc
CFLAGS = -g -lm -Wall -std=c99
OBJECTS = gauss_jordan.o
all : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o gauss_jordan


gauss_jordan: .c
	$(CC) $(CFLAGS) -c gauss_jordan.c
