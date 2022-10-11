CFLAGS=
CC=gcc
LIB=./src/lib
INCLUDE=./src/include

main: main.c $(LIB)/lib_memory_map.so
	$(CC) $(CFLAGS) main.c -o main -L$(LIB) -l_memory_map

lib_memory_map.so: $(LIB)/memory_map.c $(INCLUDE)/memory_map.h
	$(CC) $(CFLAGS) -fPIC -shared $(LIB)/memory_map.c -o $(LIB)/lib_memory_map.so -lc

install:
	sudo ln -s ~/Desktop/Linux_M2_Final/src/lib/lib_memory_map.so /usr/lib/

unistall:
	sudo rm /usr/lib/lib_memory_map.so

.PHONY: all clean install

