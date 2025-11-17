#include <stdio.h>
#include <stdlib.h>
#define DIM 100
void scambio(int *a,int *b) {
    int t=*a;
    *a=*b;
    *b=t;
}
void bubble1(int v[],int n) {
        int k,sup;
        for(sup =n-1; sup>0; sup --) {
            for(k=0; k<sup; k++) {
                if(v[k]>v[k+1]) {
                    scambio(&v[k],&v[k+1]);
                }
            }
        }
}
void stampaVett(int v[],int n){
    printf("valori ordinati:\n");
    for(int k=0;k<n;k++){
        if(v[k] !=0){
            printf("%d\n",v[k]);
        }  
    }
}
int main(int argc, char **argv){
    int vett[DIM];
    int i=0;
       for(int k=1;k<argc;k++){
        if(*argv[k]>=1 || *argv[k] <= 9){
            vett[i]=atoi(argv[k]);
            i++;
        }
       }
bubble1(vett,i);
stampaVett(vett,i);
return 0;
}