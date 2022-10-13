CFLAGS=
CC=gcc
LIB=./src/lib
INCLUDE=./src/include

test: test.c $(LIB)/lib_memory_leaks.so $(LIB)/lib_memory_map.so
	$(CC) $(CFLAGS) test.c -o test -L$(LIB) -l_memory_leaks -l_memory_map

lib_memory_leaks.so: $(LIB)/memory_leaks.c $(INCLUDE)/memory_leaks.h
	$(CC) $(CFLAGS) -fPIC -shared $(LIB)/memory_leaks.c -o $(LIB)/lib_memory_leaks.so -lc

lib_memory_map.so: $(LIB)/memory_map.c $(INCLUDE)/memory_map.h
	$(CC) $(CFLAGS) -fPIC -shared $(LIB)/memory_map.c -o $(LIB)/lib_memory_map.so -lc

install:
	sudo ln -s /home/raul/Documents/Linux/Linux_M2_Final/src/lib/lib_memory_leaks.so /usr/lib/
	sudo ln -s /home/raul/Documents/Linux/Linux_M2_Final/src/lib/lib_memory_map.so /usr/lib/

unistall:
	sudo rm /usr/lib/lib_memory_leaks.so
	sudo rm /usr/lib/lib_memory_map.so

.PHONY: all clean install

