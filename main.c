#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "./lib/memory_leaks.h"

int main(int argc, char const *argv[])
{
    int pid = fork();

    if (pid == 0)
    {
        foo(0);
    }
    else 
    {
        wait(NULL);
    }

    return 0;
}
