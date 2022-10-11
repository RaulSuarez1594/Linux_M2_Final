#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int x=0;

void* thread_func(void* args){

    int i;
    for ( i = 0; i < 10000000; i++ )
    {
        x++; 
    } 
}