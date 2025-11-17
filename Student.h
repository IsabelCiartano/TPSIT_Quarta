#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char* name;
    int age;
    float grade;
} Student;


#define MAX_STRING_LENGTH 256

Student* createStudent(char* name, int age, float grade);//riceve i valori dei campi creano lo studente 
void setName(Student* student, char* name);//cambia nome studente x referenza pk la cambio 
char* getName(Student student);//riceve il nome dello studente x copia pk non lo cambio 
void setAge(Student* student, int age);
int getAge(Student student);
void setGrade(Student* student, float grade);
float getGrade(Student student);
void disposeStudent(Student* student);//elimina lo studente i dati 
void printStudent(Student student);
char* studentToCSV(Student student);//riceve lo studente e costruisce la linea di csv 
Student* createFromCSV(char* line);

#include "Student.c"
#endif // STUDENT_H


