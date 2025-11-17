#include <stdio.h>
#define DIM 5
int main(){
    int v[DIM]={1,2,3,4,5};
    int *p =v;
    while(p<v+DIM){
        printf("indirizzo %d\n",p);
        printf("valore %d\n",*p);
        printf("%d\n",p-v);
        p++;
    }
    return 0;
}