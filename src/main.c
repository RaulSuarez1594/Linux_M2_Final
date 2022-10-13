#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/pseudo_shell.h"
#include "include/threads_race_condition.h"

void menu(void);

enum{
	PSEUDO_SHELL = 5,
	THREADS_RACE_CONDITION,
	EXIT
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
	char arg[50];
	printf("\t *****************************************\n");
	printf("\t *****************************************\n");
	printf("\t ------		MAIN MENU	------\n");
	printf("\t *****************************************\n");
	printf("\t *****************************************\n");
	printf("\t Which program would you like to execute\?\n");
	printf("\t Select an option\n");
	printf("\t 5.pseudo shell\n");     
    printf("\t 6.threads race condition \n");
	printf("\t 7.exit \n");
	printf(">> ");
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

		case EXIT:
	 		printf("Exit was chosen!\n");
	 	break;
	 	default:
	 		printf("INVALID INPUT!\n");
	}
	printf("\n\n\n");
}
