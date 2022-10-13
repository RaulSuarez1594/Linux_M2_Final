#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Header files
#include "include/pseudo_shell.h"
#include "include/threads_race_condition.h"

void menu(void);

enum{
    PSEUDO_SHELL = 5,
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
    printf("\t [1]\n");
    printf("\t [2]\n");
    printf("\t [3]\n");
    printf("\t [4]\n");
    printf("\t [5] Pseudo shell\n");
    printf("\t [6] Threads race condition\n");
    printf("\t [7] Exit\n");
    printf(">> ");
}