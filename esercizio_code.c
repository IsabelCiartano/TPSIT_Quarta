//gestire come un ospedale i codici 
//livello di gravità in base al colore 
//bianco,verde,giallo,rosso,nero -----> enum 
//arriva una sequenza da csv di righe in cui ci sono nome e cognome (un campo)e codice
//leggere e caricare 5 code diverse per ogni colore a seconda del colore 
//output code svuotate in ordine di priorità 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 256 
typedef enum {
    BIANCO,
    VERDE,
    GIALLO,
    ROSSO,
    NERO
} Codice;

typedef struct Nodo{  // il nome nodo serve per richiamarla all'interno 
    char*nome;
    Codice cod;
    struct Nodo* next;// nodo è qui
}Node;

Node* createNode(char*nome,Codice cod){
    Node* n=(Node*)malloc(sizeof(Node));
    n->nome=strdup(nome);
    n->cod=cod;
    n->next=NULL;
    return n;
}

void show(Node* f){//ver iterativa
    while(f){
        printf("%s\n",f->nome);

        f=f->next;}
    
}
Node* in(char*nome,Codice cod,Node*f){//aggiungo in coda
    Node* saved=f;  
    if(!f)return push(nome,cod,f);
    while(f->next)f=f->next;//punta all'elemento in fondo 
    Node* new=createNode(nome,cod);
    f->next=new;
    return saved;
}
Node * out(Node*f){
    Node*ret=f->next;
    free(f);
    return ret;
}
Node* recDelete(Node*f){
    if(f){
        recDelete(f->next);
        free(f);
    }
    return NULL;
}

 Codice findCodice(char *string){
    char*codes[]={"bianco","verde","giallo","rosso","nero"}
    for(i=0;i<5,i++){
        if(strcmp(*string,codes[i])==0){
            return i;
        }
    }

}
char** splitString(char* s, char separator) {
    char** tokens = NULL;
    char delimiter[2] = {separator, '\0' };
    int count = 0;
    char* token = strtok(s, delimiter);
    while(token != NULL) {
        tokens = realloc(tokens, sizeof(char*) * (count + 1));
        
        tokens[count] = strdup(token);
        token = strtok(NULL, delimiter);
    }
    tokens = realloc(tokens, sizeof(char*) * (count + 1));
    tokens[count] = NULL;
    return tokens;
}
char* readLine(FILE* f) {
    char buffer[MAX_STRING_LENGTH];
    int i;
    for(i = 0;
        ((buffer[i]=fgetc(f))!='\n') && (buffer[i]!=EOF); //buffer temporaneo per immagazzinare i dati 
        i++) { }  
    buffer[i] = '\0';
    return (i==0)? NULL: strdup(buffer);
}



int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("uso: %s file.csv\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Errore file");
        return 1;
    }

    Node *code[5] = {NULL, NULL, NULL, NULL, NULL};

    char *line;
    while ((line = readLine(fp)) != NULL) {
        char **parts = splitString(line, ',');
        char *nome = parts[0];
        char *colore = parts[1];
        Codice c = findCodice(colore);
        code[c] = in(nome, c, code[c]);
        free(parts[0]);
        free(parts[1]);
        free(parts);
        free(line);
    }

    fclose(fp);


    printf("\nOrdine di visita:\n");

    for (int i = NERO; i >= BIANCO; i--) {
        while (code[i]) {
            printf("%s\n", code[i]->nome);
            code[i] = out(code[i]);
        }
    }

    return 0;
}

