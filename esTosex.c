#include <stdio.h>

typedef params{
    Area *f;

}

void init_field(Area* f,int m,int t,int o){
    for(int i=0;i<o*o;i++){
        *(f+i)=SAFE;
    }
    for(int i=0;i<m;i++){
        *(f+1)=MINE;
    }
    for(int i=m;i<m+t;i++){
        *(f+1)=TREASURE;
    }
    shuffle(f,o);

}

void shuffle(Area *f,int o){
    for(int i=0;i<o*o/5;i++){
        p1=rand()%(o*o);
        p2=rand()%(o*o);
        Area t=*(f+p1);
        *(f+p1)=*(f+p2);
        *(f+p2)=t;
    }
}

void * fpow(vois*p){
    Params *pp=(Params*)p;
    int ord=pp->o;
    pthread_mutex_t* mutex=pp->m;
    Area* field=pp->f;

    while(1){//al posto di uno va un flag mine treasure o safe 
        //lock, generare n casuale, vedere cosa ce nella cella, unlock 
        pthread_mutex_lock(m);
        int pos=rand()%(o*o);
        if(*(f+o)==MINE)(...)
        if(*(f+o)==TREASURE)(....)
        pthread_mutex_unlock(m);
    }
}

int main(int argc,char*argv[]){
    if(argv!=5){
        printf("*usage:/s",argv[0]);
        return -1;
    }
    int ord_field=atoi(argv[1]);
    int n_mines=atoi(argv[2]);
    int n_treasures=atoi(argv[3]);
    int n_pows=atoi(argv[4]);

    pthread_t *ids=(pthread_t)malloc(sizeof(pthread_t*n_pows));

    srand(time(NULL));
    Area * field=(Area*)malloc(sizeof(Area)*ord_field*ord_field);
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex,NULL);
    init_field(field,n_mines,n_treasures,ord_field);
    Params p={f,&mutex,ord_field};
    for(int i=0;i<n_pows;i++){
        pthread_create(*(ids+i),NULL,fpow,(void*)&p);
    }
    for(int i=0;i<n_pows;i++){
        pthread_join(ids+i,NULL)
    }



    free(field);
    free(ids);
    return 0;
}