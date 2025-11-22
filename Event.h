#ifndef EVENT_H
#define EVENT_H
#include <stdio.h>
#include <string.h> //funzioni per le stringhe 
#include <errno.h> //funzione per gli errori
#include <stdlib.h> //per uso di malloc 

#define MAX_STRING_LENGTH 256

//event struct con all'interno date 
//create event variabile statica intera =0
//getid ritorna l'intero dell'id
//setDate cambia la data puntata nel record (free prima memory leak!!!)
//free event 
//event to csv 
//sort event by name  ordinamento di vettori 
//find events in range 

Event* createEvent(char*title;Date*date);
int getId(Event* e);
void setDate(Event* e,Date* date);
void freeEvent(Event* e);
char* eventToCSV(Event* e);
void sortEventsByName(Event**events);
Event** findEventsInRange(Event** events,Date from,Date to;int* outCount);

#include "Event.c"
#endif