#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo{ 
    char key;
    struct Nodo* next;
}Node;

Node* createNode(char key){
    Node* n=(Node*)malloc(sizeof(Node));
    n->key=key;
    n->next=NULL;
    return n;
}
Node* push(char key,Node*f){
    Node* new=createNode(key);
    new->next=f;
    return new ;

}
Node * delete(Node*f,char*key){
    *key=f->key;
    Node*ret=f->next;
    free(f);
    return ret;
}

int isOpenBracket(char car){}


int main(int argc, char* argv[]){
    if(argc<2){
        printf("usage : %s string\n",argv[0]);
        return -1;
    }

    char* string=argv[1];
    Node* head=NULL;
    for(;*string;*string++){
        if(isOpenBracket(*string))
         
    }

}