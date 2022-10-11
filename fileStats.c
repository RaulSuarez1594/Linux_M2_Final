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
    printf("Size: %ld bytes\n", stats.st_size);
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
    struct passwd *pw = NULL;
    pw = getpwuid(stats.st_uid);

    if (pw == NULL)
    {
        printf("There was an error trying to get the structure :(");
    }
    else
    {
        printf("Owner: %s with an UID: %i\n", (*pw).pw_name, stats.st_uid);
    }
}

void printFileCharacterCount(char *file_)
{
}

int main(int arg, char *argv[])
{

    struct stat stats;

    if (lstat(argv[1], &stats) == 0)
    {

        /*if (printFileType(stats))
         {
             printFileCharacterCount(argv[1]);
         }
         else
         {
             printf(" \nThe alphanumeric count is: The file is not a regular file");
         }*/
        printFileSize(stats);
        printFilePropietary(stats);
        /*printFileAccess(stats);
        printFileInode(stats);
        printFileCreateDate(stats);*/
    }
    else
    {
        printf("It's impossible to get the properties");
    }
}
