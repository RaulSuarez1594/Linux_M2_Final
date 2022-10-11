#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// ----- Declaration of the mutex variable and its respective initialization -----
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int x=0;

void* thread_func(void* args){

    int i;
    for ( i = 0; i < 10000000; i++ )
    {
        pthread_mutex_lock(&mutex);//-> Allows to request access to the mutex, the thread blocks until it is obtained
        x++; 
        pthread_mutex_unlock(&mutex);//-> Allow free mutex
    } 
}

int threads_race_condition(void) {
    
    pthread_t thread_id[2];
    printf("I will create two threads\n");
    printf("Point 1 >> X is: %d\n", x);
    pthread_create(&thread_id[0],NULL,&thread_func,NULL);
    pthread_create(&thread_id[1],NULL,&thread_func,NULL);
    printf("The threads has been created\n");
    pthread_join(thread_id[0],NULL);
    pthread_join(thread_id[1],NULL);
    printf("The threads have exited\n");
    printf("Point 2 >> X is: %d\n", x);

    return 0;
}