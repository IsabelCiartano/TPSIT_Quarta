#include <stdio.h>

int main(int argc, char **argv){
    printf("i parametri passati sono : \n");
       for(int k=1;k<argc;k++){
        printf("%s \n",argv[k]);
       }
       return 0;
}