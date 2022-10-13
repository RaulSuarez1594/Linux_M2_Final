/*
	Memory leak 
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void memory_leaks(){
	char *path = NULL;

	while(1) {
		//100 bits are assigned to the path pointer variable. 
		path=malloc(100);
		//The allocated space is released 
		free(path);
		/*The path variable is set to NULL so that it no longer 
		points to the freed memory address.*/
		path = NULL;
		/*A copy of the string is dynamically created and the 
		pointer to the copy is returned.*/
		path = strdup("STRING");
		free(path);
		path = NULL;

		
	}
	

}
