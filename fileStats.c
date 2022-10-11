#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <ctype.h>
#include <time.h>

int printFileType(struct stat stats)
{

}

void printFileSize(struct stat stats)
{
   
}

void printFileAccess(struct stat stats)
{   
}

void printFileInode(struct stat stats)
{
}

void printFileCreateDate(struct stat stats)
{
    
}

void printFilePropietary(struct stat stats)
{

}

void printFileCharacterCount(char *file_)
{

}


int main(int arg, char *argv[])
{

    struct stat stats;

    if (lstat(argv[1], &stats) == 0)
    {

        if (printFileType(stats))
        {
            printFileCharacterCount(argv[1]);
        }
        else
        {
            printf(" \nThe alphanumeric count is: The file is not a regular file");
        }
        printFileSize(stats);
        printFilePropietary(stats);
        printFileAccess(stats);
        printFileInode(stats);
        printFileCreateDate(stats);
    }
    else
    {
        printf("It's impossible to get the properties");
    }
}




