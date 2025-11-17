#include <stdio.h>
#include <stdlib.h>

#define DIM1 5
#define DIM2 8

int main(){
    int **a;
    int j = 0;

    a = (int **)malloc(DIM1 * sizeof(int *));

    for(int i = 0; i < DIM1; i++){
        a[i] = (int *)malloc(DIM2 * sizeof(int));
        a[i][j] = i * j;

        printf("%d ",a[i][j]);
        j++;
    }

    for(int i = 0; i < DIM1; i++){
        free(a[i]);
    }

    free(a);

    return 0;
}