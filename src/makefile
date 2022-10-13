#COMPILER_PREFIX=../compiler/arm-linux-gnueabihf-
COMPILER_PREFIX=~/Documents/Module_2/gcc-linaro-6.4.1-2017.11-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-
CC=gcc
CFLAGS=
LIB=./lib/
SHARE=-shared -fPIC

main: main.o $(LIB)pseudo_shell.so $(LIB)threads_race_condition.so
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) main.c -lpseudo_shell -lthreads_race_condition -L$(LIB) -o main

main.o: main.c
	$(CC) -c main.c

$(LIB)pseudo_shell.so: $(LIB)pseudo_shell.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)pseudo_shell.c -o $(LIB)libpseudo_shell.so

$(LIB)threads_race_condition.so: $(LIB)threads_race_condition.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)threads_race_condition.c -o $(LIB)libthreads_race_condition.so -pthread
	
.PHONY: clean all install

install:
	@sudo cp $(LIB)*.so /usr/lib/

clean:
	@rm -f *.o ./lib/*.so main
