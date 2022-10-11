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

int spawn (char* program, char** arg_list)
{
	pid_t child_pid;
	child_pid = fork ();
	if (child_pid == 0)
    return child_pid;
	else {
		execvp (program, arg_list);
		printf("You typed something wrong");
		abort ();
	}
}