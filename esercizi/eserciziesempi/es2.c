#include<stdio.h>
#define DIM 4
int main(){
    int v[DIM];
    int max;
    printf("inserisci %d numeri:",DIM);
    for(int *k=v;k<v+ DIM;k++){
        scanf("%d",k);
        if(max<=*k)max=*k;
    }
    printf("massimo %d",max);
}