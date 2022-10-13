COMPILER_PREFIX=
CC=gcc
CFLAGS=
LIB=./lib/
INCLUDE=./include/
SHARE=-shared -fPIC

ifeq (${ARCH}, arm)
	COMPILER_PREFIX=../toolchain_linaro/gcc-linaro-6.4.1-2017.11-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-
else
	COMPILER_PREFIX=
endif

main: $(LIB)fileStats.so $(LIB)mouse_powerState.so  $(LIB)pseudo_shell.so $(LIB)threads_race_condition.so $(LIB)lib_memory_map.so $(LIB)lib_memory_leaks.so
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) main.c -lfileStats -lmouse_powerState -lpseudo_shell -lthreads_race_condition -l_memory_leaks -l_memory_map -L$(LIB) -o main

$(LIB)fileStats.so: $(LIB)fileStats.c $(INCLUDE)fileStats.h
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)fileStats.c -o $(LIB)libfileStats.so -lc

$(LIB)mouse_powerState.so: $(LIB)mouse_powerState.c $(INCLUDE)mouse_powerState.h
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)mouse_powerState.c -o $(LIB)libmouse_powerState.so -lc

$(LIB)pseudo_shell.so: $(LIB)pseudo_shell.c $(INCLUDE)pseudo_shell.h
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)pseudo_shell.c -o $(LIB)libpseudo_shell.so -lc

$(LIB)threads_race_condition.so: $(LIB)threads_race_condition.c $(INCLUDE)threads_race_condition.h
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)threads_race_condition.c -o $(LIB)libthreads_race_condition.so -pthread -lc

$(LIB)lib_memory_leaks.so: $(LIB)memory_leaks.c $(INCLUDE)memory_leaks.h
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)memory_leaks.c -o $(LIB)lib_memory_leaks.so -lc 

$(LIB)lib_memory_map.so: $(LIB)memory_map.c $(INCLUDE)memory_map.h
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)memory_map.c -o $(LIB)lib_memory_map.so -lc
	
.PHONY: clean all install
all: main 

install:
	@sudo ln -s -f /home/raul/Documents/Linux/Linux_M2_Final/src/lib/*.so /usr/lib/

clean:
	@rm -f ./lib/*.so main
