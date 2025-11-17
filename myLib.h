#ifndef MYLIB_H //se non è definito allora prendi in considerazione tutto fino ad endif
#define MYLIB_H //definisci MYLIB_H serve per non fare include più volte della stessa libreria lo fa solo una volta 

#include <stdio.h>
#include <string.h> //funzioni per le stringhe 
#include <errno.h> //funzione per gli errori
#include <stdlib.h> //per uso di malloc 

#define MAX_STRING_LENGTH 256 //non è una costante ma un simbolo in cui sostituisce la scritta con 256

//prototipi delle funzioni 

void errore(char* s, int n);
char* readLine(FILE* f);
char** splitString(char* s, char delimiter);
void disposeStringArray(char** arr);//fa una free dopo aver usato splitString
int randomRange(int min, int max);//numero randomico

#include "myLib.c"

#endif // MYLIB_H

