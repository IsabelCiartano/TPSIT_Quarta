#include <stdio.h>
#include <stdlib.h>

typedef struct N {
    char key;
    struct N *next;
} Node;

Node* newStack();
int isEmpty(Node *s);
Node* push(Node *s, char c);
Node* newNode(char c, Node* node);
Node* pop(Node *s, char *c);
void showStack(Node *n); 
void deleteStack(Node *s);
int isOpenBracket(char c);
int isClosedBracket(char c);
int areMatched(char sx, char dx);
int isBroken(char* s); //controlla che la stringa non abbia parentesi sbagliate

//le funzioni booleane di solito hanno is o are per segnare le domande quidi è aperta isOpen 

Node* newStack() { return NULL; }

int isEmpty(Node *s) { return s == NULL; }

Node* push(Node *s, char c) { return newNode(c, s); }

Node* newNode(char c, Node* n) {
    Node* ret = malloc(sizeof(Node));
    ret->key = c;
    ret->next = n;
    return ret;
}

Node* pop(Node *s, char *c) { 
    *c = s->key;
    Node* ret = s->next;
    free(s);
    return ret;
}

void showStack(Node *n) {
    if (n) {
        showStack(n->next);
        printf("%c - ", n->key);
    } else {
        printf("NULL\n");
    }
}

void deleteStack(Node *s) {
    if (s) {
        deleteStack(s->next);
        free(s);
    }
}

int isOpenBracket(char c) {
    return c == '(' || c == '[' || c == '<' || c == '{';
}

int isClosedBracket(char c) {
    return c == ')' || c == ']' || c == '>' || c == '}';
}

int areMatched(char sx, char dx) {
    char *openBrackets = "([<{"; //due vettori di caratteri  con le parentesi quindi 2 stringhe 
    char *closedBrackets = ")]>}";
    
    for (; *openBrackets; openBrackets++, closedBrackets++)
    //ciclo si chiede se arriva al fondo ad ogni ciclo incremento tutte e due le stringhe 1++,2++
        if (sx == *openBrackets && dx == *closedBrackets) 
            return 1;
    
    return 0;
}

int isBroken(char* s) {// constrolla la stringa 
    Node *stack = newStack();//creazione stack vuoto
    int result = 0;
    
    for (; *s; s++) {//scorre tutta la stringa
        if (isOpenBracket(*s)) {
            stack = push(stack, *s);//mette la parentesi nell stack 
        }
        if (isClosedBracket(*s)) {
            if (isEmpty(stack)) {//parentesi chiusa ma stack vuoto è gia sbagliata 
                result = 1;
                break;//esce dal for   
            }
            char c;
            stack = pop(stack, &c);
            if (!areMatched(c, *s)) {
                result = 1;
                break;
            }
        }
    }
    
    if (!result) result = !isEmpty(stack); 
    
    deleteStack(stack);//memory leak
    
    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s STRING\n", argv[0]);  
        return -1;
    }
    
    int ret = isBroken(argv[1]);
    
    if (ret) 
        printf("The string is BROKEN: brackets don't match.\n"); 
    else
        printf("The string is CORRECT: brackets match!\n");
    
    return ret == 0;
}
