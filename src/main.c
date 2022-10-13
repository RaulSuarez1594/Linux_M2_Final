#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "include/pseudo_shell.h"
#include "include/threads_race_condition.h"
#include "include/mouse_powerState.h"
#include "include/fileStats.h"

void menu(int argc, char** argv);

enum{
	FILESTATS = 1,
	MOUSE_POWERSTATE = 2,
	PSEUDO_SHELL = 5,
	THREADS_RACE_CONDITION
};

int gOption = 0;

int main(int argc, char **argv)
{
	do
	{
		menu(argc, argv);
	} while (gOption != 7);

	return EXIT_SUCCESS;
}

void menu(int argc, char **argv)
{
	char arg[100];
	printf("\t *****************************************\n");
	printf("\t ------		Main menu	------\n");
	printf("\t *****************************************\n");
	printf("\t Which program would you like to execute\?\n");
	printf("\t Select an option\n");
	printf("\t [1]file stats  [2] mouse power state [5] pseudo shell     [6] threads race condition      [7] exit\n");
	scanf("%d",&gOption);
	system("clear");

	switch(gOption){
		case FILESTATS:
			printFileStats(argc, argv);
			break;
		case MOUSE_POWERSTATE:
			//If you want to use this program, you must run main program as root user.
			suspend_RAM(argc, argv);
		break;
		case PSEUDO_SHELL:
			printf("Pseudo-command?\n");
            printf("fecha, quiensoy, tiempo, modulos\n");
			scanf("%s", arg);
            pseudo_shell(2, arg);
		break;

		case THREADS_RACE_CONDITION:
			threads_race_condition();
		break;

		default:
            printf("Invalid option\n");
	}
	printf("\n\n\n");
}
