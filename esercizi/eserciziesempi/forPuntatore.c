#include <stdio.h>
#define DIM 5
int main(){
    int v[DIM]={1,2,3,4,5};
    for(int *p =v;p<v+DIM;p++){
        printf("indirizzo %d\n",p);
        printf("valore %d\n",*p);
        printf("%d",p-v);
    }
    return 0;
}