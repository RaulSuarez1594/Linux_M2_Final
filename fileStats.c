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
    printf("\nFile Permissions: ");
    printf( (S_ISDIR(stats.st_mode)) ? "d" : "-");
    printf( (stats.st_mode & S_IRUSR) ? "r" : "-");
    printf( (stats.st_mode & S_IWUSR) ? "w" : "-");
    printf( (stats.st_mode & S_IXUSR) ? "x" : "-");
    printf( (stats.st_mode & S_IRGRP) ? "r" : "-");
    printf( (stats.st_mode & S_IWGRP) ? "w" : "-");
    printf( (stats.st_mode & S_IXGRP) ? "x" : "-");
    printf( (stats.st_mode & S_IROTH) ? "r" : "-");
    printf( (stats.st_mode & S_IWOTH) ? "w" : "-");
    printf( (stats.st_mode & S_IXOTH) ? "x" : "-");
}

void printFileInode(struct stat stats)
{
    printf("\nInode: %d", stats.st_ino);
}

void printFileCreateDate(struct stat stats)
{
    struct tm dt;
    dt = *(gmtime(&stats.st_ctim));
    printf("\nCreate on: %02d-%02d-%02d %02d:%02d:%02d \n", dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900, dt.tm_hour - 5, dt.tm_min, dt.tm_sec);
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
        printf("Impossible get the properties");
    }
}