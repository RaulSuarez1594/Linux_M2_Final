CFLAGS=-Wall
CC=gcc

main: main.c lib_memory_leaks.so
	$(CC) $(CFLAGS) main.c -o main -L. -lib_memory_leaks

lib_memory_leaks.so: ./lib/memory_leaks.c ./lib/memory_leaks.h
	$(CC) $(CFLAGS) -fPIC -shared ./lib/memory_leaks.c -o lib_memory_leaks.so -lc

.PHONY: all clean install