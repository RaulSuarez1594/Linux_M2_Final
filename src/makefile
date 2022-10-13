COMPILER_PREFIX=
CC=gcc
CFLAGS=
LIB=./lib/
SHARE=-shared -fPIC

ifeq (${ARCH}, arm)
	COMPILER_PREFIX=../toolchain_linaro/gcc-linaro-6.4.1-2017.11-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-
else
	COMPILER_PREFIX=
endif

.PHONY:  all install clean

all: main

main: main.o $(LIB)fileStats.so $(LIB)mouse_powerState.so  $(LIB)pseudo_shell.so $(LIB)threads_race_condition.so 
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) main.c -lfileStats -lmouse_powerState -lpseudo_shell -lthreads_race_condition -L$(LIB) -o main

$(LIB)fileStats.so: $(LIB)fileStats.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)fileStats.c -o $(LIB)libfileStats.so

$(LIB)mouse_powerState.so: $(LIB)mouse_powerState.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)mouse_powerState.c -o $(LIB)libmouse_powerState.so

$(LIB)pseudo_shell.so: $(LIB)pseudo_shell.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)pseudo_shell.c -o $(LIB)libpseudo_shell.so

$(LIB)threads_race_condition.so: $(LIB)threads_race_condition.c
	$(COMPILER_PREFIX)$(CC) $(CFLAGS) $(SHARE) $(LIB)threads_race_condition.c -o $(LIB)libthreads_race_condition.so -pthread

install:
	sudo cp $(LIB)*.so /usr/lib/

clean:
	@rm -f *.o ./lib/*.so main