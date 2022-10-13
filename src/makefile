COMPILER_PREFIX=../toolchain_linaro/gcc-linaro-6.4.1-2017.11-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-
CC=gcc
CFLAGS=
LIB=./lib/
SHARE=-shared -fPIC

main: $(LIB)pseudo_shell.so $(LIB)threads_race_condition.so
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) main.c -lpseudo_shell -lthreads_race_condition -L$(LIB) -o main

$(LIB)pseudo_shell.so: $(LIB)pseudo_shell.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)pseudo_shell.c -o $(LIB)libpseudo_shell.so

$(LIB)threads_race_condition.so: $(LIB)threads_race_condition.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)threads_race_condition.c -o $(LIB)libthreads_race_condition.so -pthread
	
.PHONY: clean all install
all: main 

install:
	@sudo cp $(LIB)*.so /usr/lib/

clean:
	@rm -f ./lib/*.so main
