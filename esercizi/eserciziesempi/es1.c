#include <stdio.h>

int main(int argc,char **argv){
    int vett[10];
    int *pi;
    pi=vett;
    printf("%p\n",vett);
    printf("%p",pi);
    printf("\n%d",*(vett+20));
    return 0;
}