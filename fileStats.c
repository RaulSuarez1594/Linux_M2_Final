#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <ctype.h>
#include <time.h>

int printFileType(struct stat stats)
{
    printf("\nFile Type: ");
    switch (stats.st_mode & S_IFMT)
    {
    case S_IFSOCK:
        printf("Socket");
        break;
    case S_IFLNK:
        printf("Symbolic link");
        break;
    case S_IFREG:
        printf("Regular File");
        return 1;
    case S_IFBLK:
        printf("Block device");
        break;
    case S_IFDIR:
        printf("Directory");
        break;
    case S_IFCHR:
        printf("Char device");
        break;
    case S_IFIFO:
        printf("pipe");
        break;
    default:
        printf("Unknown-");
        break;
    }
    return 0;
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

}


    printf("\nThe alphanumeric count is : %i /n", characters);
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

