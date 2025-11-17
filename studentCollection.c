/* studentsCollection.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "myLib.h" 
#include "Student.h"

Student** loadStudentsFromFile(FILE* f, int* outCount);//carica gli studenti da file 
void saveStudentsToFile(FILE* file, Student** students);
void disposeStudentArray(Student** students);

int main(int argc, char* argv[]) {//come paramentri passati durante l'esecuzione richiede il file di input e di output
    
    if ((argc != 2) && (argc != 3)) {
        printf("Usage: %s <fileInput> [<fileOutput>]\n", argv[0]);//[vuol die che non è necessario ]
        return 1;
    }
    
    char* filenameIn = argv[1];//per avere nomi leggibili 
    char* filenameOut = argv[2];
    
    printf("Loading students from file: %s...\n", filenameIn);
    FILE* fileIn = fopen(filenameIn, "r");
    if(fileIn == NULL)  errore("fopen()", 2);//errrore sull'apertura 
    int studentsCount;//nStudenti 
    Student** students = loadStudentsFromFile(fileIn, &studentsCount);//passaggio referenza &
    fclose(fileIn);//chiudo il file
    printf("Loaded %d students from %s.\n", studentsCount, filenameIn);

    for(Student** temp = students; *temp; temp++) {
        printStudent(**temp);
    }   

    srand(time(NULL));//seed casuale 
    printf("Updating students' ages and grades... ");
    for(Student** temp = students; *temp; temp++) {
        setAge(*temp, getAge(**temp) + 1);
        setGrade(*temp, randomRange(20, 100)/10.0);
    }
    printf("Done.\n");

    if(filenameOut != NULL) {
        
        printf("Saving students to file: %s...\n", filenameOut);
        FILE* fileOut = fopen(filenameOut, "w");
        if(fileOut == NULL)  errore("fopen()", 3);
        saveStudentsToFile(fileOut, students);
        printf("Saved %d students to %s.\n", studentsCount, filenameOut);
        fclose(fileOut);
    }
    
    printf("Disposing students...\n");
    disposeStudentArray(students);

    return 0;
}

Student** loadStudentsFromFile(FILE* f, int* outCount) {
    char* line;
    Student** students = NULL;
    int count = 0;
    
    while((line = readLine(f)) != NULL) {//legge una riga 
        Student* student = createFromCSV(line);//crea uno studente con i parametri giusti 
        students = realloc(students, sizeof(Student*) * (count + 1));//fa una free e po una mallo                   
        students[count] = student;
        count++;
        free(line);//mallo c per line quindi bisogna fare la free
    }
    students = realloc(students, sizeof(Student*) * (count + 1));//aggiunge uno studente con valore null per sapere che finisce 
    students[count] = NULL; // Terminatore
    
    *outCount = count;//intero passato per referenza per far in modo che so quanti studenti ho creato 
    return students;//mi ritorna studenti 
}

void saveStudentsToFile(FILE* file, Student** students) {
    for(Student** temp = students; *temp; temp++) {
        char* csvLine = studentToCSV(**temp);//chaimata a funzioen in student.c
        fprintf(file, "%s\n", csvLine);
        free(csvLine);//elimina riga per prendere la prossima 
    }
}

void disposeStudentArray(Student** students) {
    for(Student** temp = students; *temp; temp++) {
        disposeStudent(*temp);//devo eliminare lo studente pk è un vettore di studenti
        //in studenti non ce un solo valore ma nome eta ecc... 
    }
    free(students);
}
