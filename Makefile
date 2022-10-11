CFLAGS=
CC=gcc
LIB=./src/lib
INCLUDE=./src/include

main: main.c $(LIB)/lib_memory_leaks.so
	$(CC) $(CFLAGS) main.c -o main -L$(LIB) -l_memory_leaks

lib_memory_leaks.so: $(LIB)/memory_leaks.c $(INCLUDE)/memory_leaks.h
	$(CC) $(CFLAGS) -fPIC -shared $(LIB)/memory_leaks.c -o $(LIB)/lib_memory_leaks.so -lc

install:
	sudo ln -s ~/Desktop/Linux_M2_Final/src/lib/lib_memory_leaks.so /usr/lib/

unistall:
	sudo rm /usr/lib/lib_memory_leaks.so

.PHONY: all clean install

