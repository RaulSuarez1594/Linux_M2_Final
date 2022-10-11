/**
 * This program receives a pseudo-command as a main() parameter 
 * that indicates which command it should execute in a child 
 * process with the help of fork()/exec().
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>