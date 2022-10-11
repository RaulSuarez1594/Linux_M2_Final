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
    struct tm dt;
    dt = *(gmtime(&stats.st_ctim));
    printf("\nCreate on: %02d-%02d-%02d %02d:%02d:%02d \n", dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900, dt.tm_hour - 5, dt.tm_min, dt.tm_sec);
}

void printFilePropietary(struct stat stats)
{
    struct passwd pws;
    pws = *getpwuid(stats.st_uid);
    printf("\nPropietary: %s, User UID %d ", pws.pw_name, stats.st_uid);
}

void printFileCharacterCount(char *file_)
{
    char ch;
    FILE *file;
    int characters = 0;
    file = fopen(file_, "r");
    if (file == NULL)
    {
        printf("\nCannot open file %s", file_);
    }

    while (!feof(file))
    {
        ch = fgetc(file);
        if (isalpha(ch) || isdigit(ch))
        {
            characters++;
        }
    }

    printf("\nThe alphanumeric count is : %i ", characters);
    fclose(file);
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
        printf("Impossible get the properties");
    }
}