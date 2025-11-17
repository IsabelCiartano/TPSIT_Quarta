// Student.c

Student* createStudent(char* name, int age, float grade) {
    Student* student = (Student*)malloc(sizeof(Student));
    student->name = strdup(name);
    student->age = age;
    student->grade = grade;
    return student;
}
void setName(Student* student, char* name) {
    free(student->name);//free del nome e poi sostituisce 
    student->name = strdup(name);
}
char* getName(Student student) {
    return strdup(student.name);
}
void setAge(Student* student, int age) {
    student->age = age;
}
int getAge(Student student) {
    return student.age;
}
void setGrade(Student* student, float grade) {
    student->grade = grade;
}
float getGrade(Student student) {
    return student.grade;
}
void disposeStudent(Student* student) {
    free(student->name);//pulisce puntatori interni al record student 
    free(student);//pulisce il record 
}
void printStudent(Student student) {
    printf("Name: %s, Age: %3d, Grade: %.2f\n", student.name, student.age, student.grade);
}
char* studentToCSV(Student student) {
    static char buffer[MAX_STRING_LENGTH];//allocare il buffer prima 
    sprintf(buffer, "%s,%d,%.2f", student.name, student.age, student.grade);//printf che fa dentro una stringa no stdout ma su una stringa 
    return strdup(buffer);//non posso fare il return di buffer pk quando finisce la funzione buffer si dealloca 
}

Student* createFromCSV(char* csvLine) {
    Student* student; //crea puntatore a studente 
    char** tokens = splitString(csvLine, ',');//divide la stringa 
    char* name = tokens[0];//primo token è il nome
    int age = atoi(tokens[1]);//secondo age atoi pk è un intero i
    float grade = atof(tokens[2]);//terzo grade atof pk è un decimale float f
    student = createStudent(name, age, grade);
    disposeStringArray(tokens);
    return student;
}
