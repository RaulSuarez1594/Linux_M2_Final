#include "../include/fileStats.h"

int printFileStats(int agrc, char *argv)
{
    struct stat stats;

    if (lstat(argv, &stats) == 0)
    {
        if (printFileType(stats))
        {
            printFileCharacterCount(argv);
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

//TO DO: make the other functions indepent of an stat struct

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
    printf("Size: %ld bytes\n", stats.st_size);
}

void printFileAccess(struct stat stats)
{
    printf("File Permissions: ");
    printf((S_ISDIR(stats.st_mode)) ? "d" : "-");
    printf((stats.st_mode & S_IRUSR) ? "r" : "-");
    printf((stats.st_mode & S_IWUSR) ? "w" : "-");
    printf((stats.st_mode & S_IXUSR) ? "x" : "-");
    printf((stats.st_mode & S_IRGRP) ? "r" : "-");
    printf((stats.st_mode & S_IWGRP) ? "w" : "-");
    printf((stats.st_mode & S_IXGRP) ? "x" : "-");
    printf((stats.st_mode & S_IROTH) ? "r" : "-");
    printf((stats.st_mode & S_IWOTH) ? "w" : "-");
    printf((stats.st_mode & S_IXOTH) ? "x" : "-");
}

void printFileInode(struct stat stats)
{
    printf("\nInode: %lu", stats.st_ino);
}

void printFileCreateDate(struct stat stats)
{
    struct tm dt;
    dt = *(gmtime(&stats.st_ctim));
    printf("\nCreate on: %02d-%02d-%02d %02d:%02d:%02d \n", dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900, dt.tm_hour - 5, dt.tm_min, dt.tm_sec);
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

    printf("\nThe alphanumeric count is : %i \n", characters);
    fclose(file);
}
