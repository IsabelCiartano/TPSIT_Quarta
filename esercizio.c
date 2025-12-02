#include <stdio.h>

typedef enum  {//tipo di dato che può avere solo alcuni tdeterminati valori 
    ASINO,
    EQUINO,
    QUELLO_NORMALE,
    SECCHIONE,
    BALZATORE
}Type;

typedef struct {
    char* nome;
    type ranking;
    float voto;
}Student;
    
Student* create(float voto,char*nome,Type ranking){
    Student* s=(Student*)malloc(sizeof(Student));
    s->nome=strdup(nome);
    s->voto=voto;
    s->ranking=ranking;

    return s; 
}

int main(){
    Type t=ASINO;//variabile che vale come un int 4 byte 
    //no fare una free e come un intero cioè è un primitivo    
     int s=sizeof(Type);
    printf("%d",s);
}