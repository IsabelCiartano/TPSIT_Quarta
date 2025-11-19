#ifndef DATE_H
#define DATE_H
//date struct
//implementare date.h 
//createdate
//free date 
//date form csv
//date to csv
//datesfrom csv
//date compare 

//event struct con all'interno date 
//create event variabile statica intera =0
//getid ritorna l'intero dell'id
//setDate cambia la data puntata nel record (free prima memory leak!!!)
//free event 
//event to csv 
//sort event by name  ordinamento di vettori 
//find events in range 

Date*createDate(int gg,int mm,int aa);
void freeDate(Date *d);
