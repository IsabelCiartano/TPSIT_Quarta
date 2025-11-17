#ifdef MYLIB_H
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define MAX_STRING_LENGH 256

void errore(char *s,int n);
char* readLine(FILE*f);
char** splitString(char* s,char delimiter);
void disposeStringArray(char** arr);
int randomRange(int min,int max);

#endif