
//struttura ricorsiva per definire struct A uso struct A
typedef struct Nodo{  // il nome nodo serve per richiamarla all'interno 
    int key;
    struct Nodo* next;// nodo è qui
}Node;

Node* createNode(int key){
    Node* n=(Node*)malloc(sizeof(Node));
    n->key=key;
    n->next=NULL;
    return n;
}


void show(Node* f){//ver iterativa
    while(f){
        printf("%d\n",f->key);
        f=f->next;}
    
}

void showrec(Node*f){//ver ricorsiva
     if(f){printf("%d\n",f->key);
        show(f->next);
        
    }
}

Node* in(int k,Node*f){//aggiungo in coda
    Node* saved=f;  
    if(!f)return push(key,f);
    while(f->next)f=f->next;//punta all'elemento in fondo 
    Node* new=createNode(key);
    f->next=new;
    return saved;
}



Node * out(Node*f,int*key){
    *key=f->key;
    Node*ret=f->next;
    free(f);
    return ret;
}//cancella il primo elemento //pop delete dello stack
//restituisce anche key ciò la chiave del nodo che ha cancellato 

Node* recDelete(Node*f){
    if(f){
        recDelete(f->next);
        free(f);
    }
    return NULL;
}
 Node* newlist(){
    return NULL;
 }

int main(char* argv[],int args){
    Node n;
    n.a=3;
    n.b=10;
    Node *f=newlist();
    for(;*argv;argv++){
        int key=atoi(*argv);
        f=push(key,f);
    }
    showrec(f);
    recDelete(f); 
  
return 0;
}