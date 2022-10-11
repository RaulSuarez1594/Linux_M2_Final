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
	char s;//-> Variable used to store a character to identify the action to execute.
// ----- Comparison of the entered argument with the available options -----
	if(strcmp("fecha",argv[1]) == 0)
		s = 'f';
	else if (strcmp("quiensoy",argv[1]) == 0)
		s = 'q';
	else if (strcmp("tiempo",argv[1]) == 0)
		s = 't';
	else if (strcmp("personal",argv[1]) == 0)
		s = 'p';
	else 
		s = 'e';
// ----- Detection of the selected option and sends the necessary parameters to the "" function -----
	switch(s)
	{
		case 'f':
			{
				char* arg_list[] = {
					"date",
					NULL
					};
				
				spawn("date", arg_list);
				break;
			}
		case 'q':
			{
				char* arg_list[] = {
					"whoami",
					NULL
				};	
				spawn("whoami", arg_list);
				break;
			}
		case 't':
			{
				char* arg_list[] = {
					"uptime",
					"-p",
					NULL
				};	
				spawn("uptime", arg_list);
				break;
			}
		case 'p':
			{
				char* arg_list[] = {
					"/home/jaret/Desktop/Moodle/1_Sistemas_de_archivos/Informacion_y_manipulacion_de_archivos/Jaret",
					"/home/jaret/Desktop/prueba",
					NULL
				};	
				spawn("/home/jaret/Desktop/Moodle/1_Sistemas_de_archivos/Informacion_y_manipulacion_de_archivos/Jaret", arg_list);
				break;
			}
		default:
			printf("Option not available\n");
			break;
	}
	wait(NULL);
	return 0;
}