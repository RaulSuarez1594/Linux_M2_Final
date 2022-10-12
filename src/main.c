#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/pseudo_shell.h"
#include "include/threads_race_condition.h"

void menu(void);

enum{
	PSEUDO_SHELL = 5,
	THREADS_RACE_CONDITION
};

int gOption = 0;

int main(int argc, char **argv)
{
	do
	{
		menu();
	} while (gOption != 7);

	return EXIT_SUCCESS;
}


void menu(void)
{
	char arg[100];
	printf("\t *****************************************\n");
	printf("\t ------		Main menu	------\n");
	printf("\t *****************************************\n");
	printf("\t Which program would you like to execute\?\n");
	printf("\t Select an option\n");
	printf("\t [5] pseudo shell     [6] threads race condition      [7] exit\n");
	scanf("%d",&gOption);
	system("clear");

	switch(gOption){
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
