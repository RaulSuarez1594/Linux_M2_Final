#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <ctype.h>
#include <time.h>

int printFileStats(int argc, char *argv);
int printFileType(struct stat stats);
void printFileSize(struct stat stats);
void printFileAccess(struct stat stats);
void printFileInode(struct stat stats);
void printFileCreateDate(struct stat stats);
void printFilePropietary(struct stat stats);
void printFileCharacterCount(char *file_);
