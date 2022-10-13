#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void main(){
	char *path = NULL;
    	int itr = 0;

	while(itr < 1000) {
            // A free call must exist for every malloc call
	    path = malloc(100);
	    free(path);
            path = NULL;

            //strdup() returns a pointer to a null-terminated string
            //the memory obtained is done dynamically using malloc and hece it can be freed using free.
	    path = strdup("STRING");
            free(path);
	    path = NULL;

            itr++;
	}
}

