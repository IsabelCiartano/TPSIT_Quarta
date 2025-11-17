#include <stdio.h>
#include <stdlib.h>

int main(){
    int *v=NULL;
    int *pdim=NULL;
    printf("inserisci dimensione array->");
    scanf("%d",pdim);

    v=(int*)malloc(*pdim * sizeof(int));
    for(int *p =v;p<v+*pdim;p++){
        printf("inserisci un numero->");
        scanf("%d",p);
        printf("valore %d\n",*p);
    }
    free(v);
    return 0;
}