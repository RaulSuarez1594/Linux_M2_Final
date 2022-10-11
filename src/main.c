#include <stdlib.h>
#include <stdio.h>

#include "include/pseudo_shell.h"
#include "include/threads_race_condition.h"

int main(int argc, char** argv)
{
    int num=0;
    printf("Que programa deseas ejecutar?\n");
    printf("5. Pseudo_shell\n");
    printf("6. Threads_race_condition\n");
    scanf("%d", &num);

    switch(num)
    {
        case 5:
            char* arg;
            printf("Pseudo-command?\n");
            printf("fecha, quiensoy, tiempo, personal\n");
            scanf("%s", arg);
            pseudo_shell(2,arg);
        break;
        case 6:
            threads_race_condition();
        break;
        default:
            printf("Invalid option\n");
        break;
    }
    
    return 0;
}
