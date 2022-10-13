#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "./src/include/memory_leaks.h"

int main(int argc, char const *argv[])
{
    int pid = fork();

    if (pid == 0)
    {
        memory_leaks();
    }
    else 
    {
        wait(NULL);
    }

    return 0;
}
