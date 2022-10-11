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
	if (child_pid != 0)
    return child_pid;
	else {
		execvp (program, arg_list);
		printf("You typed something wrong");
		abort ();
	}
}
// ----- Principal function -----
int pseudo_shell (int argc, char *argv[])
{	
	//Checks that the pseudo-command is correct.
    //Loads necessary arguments and call function to execute it
    if (strcmp(argv[1],"fecha") == 0)
    {
        char* arg_list[] = {
            "date",
            NULL
        };
        spawn("date", arg_list);
    }
    else if (strcmp(argv[1],"quiensoy") == 0)
    {
        char* arg_list[] = {
            "whoami",
            NULL
        };
        spawn("whoami", arg_list);
    }
    else if (strcmp(argv[1],"tiempo") == 0)
    {
        char* arg_list[] = {
            "uptime",
            "-p",
            NULL
        };
        spawn("uptime", arg_list);
    }
    else if (strcmp(argv[1],"personal") == 0)
    {
        char* arg_list[] = {
            "../A1/test",
            "../A1/mitexto.txt",
            NULL
        };
        spawn("../A1/test", arg_list);
    }
    else
    {
        printf("Error in the Pseudo-command\n");
    }
    
    wait(NULL); //wait for the child process to finish
	return 0;
}