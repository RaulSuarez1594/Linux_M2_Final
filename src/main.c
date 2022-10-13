#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Header files
#include "include/pseudo_shell.h"
#include "include/threads_race_condition.h"
#include "include/mouse_powerState.h"
#include "include/fileStats.h"
#include "include/memory_leaks.h"
#include "include/memory_map.h"

void menu(void);

enum{
	FILESTATS = 1,
	MOUSE_POWERSTATE,
	MEMORY_MAP,
    MEMORY_LEAKS,
    PSEUDO_SHELL,
	THREADS_RACE_CONDITION,
    EXIT
};

int pause(void){
    char pausa[20];
    printf("\n\n\n\nPress any character on the keyboard and then the ENTER key\n");
    scanf("%s",pausa);    
}

int main(){

    int gOption = 0;
    char subOption,arg[100];
    do{
        menu();
        scanf("%d", &gOption);
        system("clear");
        switch(gOption){
            case FILESTATS:
                printf("Type the file?\n");
                scanf("%s", arg);
                printFileStats(1, arg);
                break;
		    case MOUSE_POWERSTATE:
                //If you want to use this program, you must run main program as root user.
                printf("Type the direction?\n");
                scanf("%s", arg);
                suspend_RAM(1, arg);
		        break;
            case MEMORY_MAP:
                int pid = fork();
                int exit_status = 0;
                if (pid == 0)
                {
                    memory_map(0);
                    return -1;
                }
                else
                {
                    exit_status = wait(NULL);
                }                
                break;
            case MEMORY_LEAKS:
                memory_leaks();
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
             case EXIT:
                printf("Exit was chosen!\n");
                break;
             default:
                printf("INVALID INPUT!\n");
        }
        if(gOption!= 7)
            pause();
        else
            sleep(2);
        system("clear");
    }while(gOption != 7);
    return EXIT_SUCCESS;
}

void menu(void)
{
    printf("\t *****************************************\n");
    printf("\t *****************************************\n");
    printf("\t ------          MAIN MENU          ------\n");
    printf("\t *****************************************\n");
    printf("\t *****************************************\n");
    printf("\t Which program would you like to execute\?\n");
    printf("\t Select an option\n");
    printf("\t [1] file stats \n");
    printf("\t [2] mouse power state \n");
    printf("\t [3] memory map\n");
    printf("\t [4] memory leaks\n");
    printf("\t [5] Pseudo shell\n");
    printf("\t [6] Threads race condition\n");
    printf("\t [7] Exit\n");
    printf(">> ");
}
