#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    printf("inizio processo");
    int a=fork();
    if(a){
        printf("im the parent");
    }else{
        char* cmd[]={"lshw",NULL}
        printf("im the child");
        execvp(*cmd,cmd);
        printf("non sono riuscito a eseguirlo");
//se cambia come comando non lo eseguirà mai lo esegue solo se non ha cambiato eseguibile 
//sudo apt install build-essential 
    }
    printf("sono il processo numero %d e valgo [%d]\n",getpid(),a);
    return 0;
}