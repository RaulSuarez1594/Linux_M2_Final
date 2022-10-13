#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void memory_leaks(){
	char *path = NULL;
	char *copy = NULL;

	while(1) {
		path=malloc(100);
	    copy = strdup("STRING");
        free(path);
		free(copy);
	}

}