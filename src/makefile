#COMPILER_PREFIX=../compiler/arm-linux-gnueabihf-
COMPILER_PREFIX=
CC=gcc
CFLAGS=
LIB=./lib/
SHARE=-SHARED -fPIC

main: main.o
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) main.o -lpseudo_shell -lthreads_race_condition -L$(LIB) -o main

main.o: main.c
	$(CC) -c main.c

$(LIB)pseudo_shell.so: $(LIB)pseudo_shell.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)pseudo_shell.c -o libpseudo_shell.so

$(LIB)threads_race_condition.so: $(LIB)threads_race_condition.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)threads_race_condition.c -o libthreads_race_condition.so

