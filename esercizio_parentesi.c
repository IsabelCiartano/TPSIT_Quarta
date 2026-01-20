#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    char key;
    struct Nodo* next;
} Node;

Node* createNode(char key) {
    Node* n = malloc(sizeof(Node));
    n->key = key;
    n->next = NULL;
    return n;
}

Node* push(char key, Node* f) {
    Node* new = createNode(key);
    new->next = f;
    return new;
}

Node* pop(Node* f) {
    Node* ret = f->next;
    free(f);
    return ret;
}

int isOpenBracket(char c) {
    return (c == '(' || c == '[' || c == '{');
}

int isCloseBracket(char c) {
    return (c == ')' || c == ']' || c == '}');
}

int isMatching(char close, char open) {
    return (close == ')' && open == '(') ||
           (close == ']' && open == '[') ||
           (close == '}' && open == '{');
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("usage: %s string\n", argv[0]);
        return -1;
    }

    char* string = argv[1];
    Node* head = NULL;

    for (; *string; string++) {
        if (isOpenBracket(*string)) {
            head = push(*string, head);
        } else if (isCloseBracket(*string)) {
            if (head == NULL || !isMatching(*string, head->key)) {
                printf("erroe\n");
                return -2;
            }
            head = pop(head);
        }
    }

    if (head == NULL)
        printf("Parentesi bilanciate\n");
    else
        printf("error\n");

    return 0;
}
