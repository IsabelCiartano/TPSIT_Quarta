#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int g;
    int m;
    int a;
} Date;

typedef struct {
    Date *d;
    char *nome;
} Person;

Person *create(char *nome, Date *d) {
    Person *a =(Person *) malloc(sizeof(Person));
   
    a->d = malloc(sizeof(Date));
    a->nome = strdup(nome);
    a->d->g = d->g;
    a->d->m = d->m;
    a->d->a = d->a;

    return a;
}

void set(char *nome, Person *a) {
    free(a->nome);
    a->nome = strdup(nome);
}

void kill(Person *a) {
    free(a->d);
    free(a->nome);
    free(a);
}

int main() {
    Date d = {27, 10, 2025};
    Person *p = create("Alice", &d);

    printf("Name: %s, Date: %d/%d/%d\n", p->nome, p->d->g, p->d->m, p->d->a);

    sets("Bob", p);
    printf("New name: %s\n", p->nome);
    printf("Name: %s, Date: %d/%d/%d\n", p->nome, p->d->g, p->d->m, p->d->a);
    kill(p);
    return 0;
}
