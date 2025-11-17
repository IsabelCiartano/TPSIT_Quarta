  #include <stdio.h> 
void scambio(int *a,int *b) {
    int t=*a;
    *a=*b;
    *b=t;

}void bubble1(int *v,int n) {
        int k,sup;
        for(sup =n-1; sup>0; sup --) {
            for(k=0; k<sup; k++) {
                if(*(v+k)>*(v+k+1) ){
                    scambio((v+k),(v+k+1));
                }
            }
        }
    }

int main(){
    int v[5]={5,3,6,8,2};
    bubble1(v,5);
    for(int k=0;k<5;k++){
        printf("%d\t",*(v+k));
    }
}
