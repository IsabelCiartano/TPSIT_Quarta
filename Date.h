#ifndef DATE_H
#define DATE_H
#include <stdio.h>
#include <string.h> //funzioni per le stringhe 
#include <errno.h> //funzione per gli errori
#include <stdlib.h> //per uso di malloc 

#define MAX_STRING_LENGTH 256
//date struct
//implementare date.h 
//createdate
//free date 
//date form csv
//date to csv
//datesfrom csv
//date compare 

Date*createDate(int gg,int mm,int aa);
void freeDate(Date *d);
Date* dateFromCSV(char* s);
char* dateToCSV(Date* d);
Date** dateFromCSV(FILE* file,int*outCount);
int dateCmp(Date d1,Date d2);

#include "Date.c"
#endif