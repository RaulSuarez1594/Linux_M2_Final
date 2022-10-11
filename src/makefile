LIB=/src/lib/
OBJ = main.o libmem-leak.so libmemory_regions-overflow.so
CC = gcc
COMPILER_PREFIX=/compiler/arm-linux-gnueabihf-
CFLAGS=
DESTDIR?=/usr/lib
BASEDIR=/home/debian

.PHONY: all install clean

all: mainApp
	
install: mainApp
	sudo cp mainApp ${DESTDIR} 

clean:
	rm mainApp $(OBJ)

mainApp: $(OBJ)
	ssh -t debian@192.168.6.2 "sudo mv ${BASEDIR}/libmem-leak.so ${BASEDIR}/libmemory_regions-overflow.so ${DESTDIR}"
	$(COMPILER_PREFIX)$(CC) main.o -o mainApp -L. -lmemory_leaks -lmemory_map -lpseudo_shell - lreads_race_condition

main.o: main.c
	$(COMPILER_PREFIX)$(CC) main.c -c 

$(LIB)memory_leaks.so: $(LIB)memory_leaks.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)memory_leaks.c -o libmemory_leaks.so
	scp libmemory_leaks.so debian@192.168.6.2:${BASEDIR} 
	
$(LIB)memory_map.so: $(LIB)memory_map.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)memory_map.c -o libmemory_map.so
	scp libmemory_map.so debian@192.168.6.2:${BASEDIR} 

$(LIB)pseudo_shell.so: $(LIB)pseudo_shell.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)pseudo_shell.c -o libpseudo_shell.so
	scp libpseudo_shell.so debian@192.168.6.2:${BASEDIR} 

$(LIB)threads_race_condition.so: $(LIB)threads_race_condition.c
    $(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)threads_race_condition.c -o libthreads_race_condition.so
	scp libthreads_race_condition.so debian@192.168.6.2:${BASEDIR} 

