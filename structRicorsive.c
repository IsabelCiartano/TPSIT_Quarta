typedef struct{
    int a;
    int b;
}Node;

struct A{
    int a;
    struct A*n;//dentro il record ho un puntatore a una struttura uguale a questa 
}
//struttura ricorsiva per definire struct A uso struct A
typedef struct Nodo{  // il nome nodo serve per richiamarla all'interno 
    int key;
    struct Nodo* next;// nodo è qui
}Node;//LIFO last in first out

Node* createNode(int key,){}


/*void show(Node* f){
    do{
        printf("%d\n",f->key);
        f=f->next;
    }while(f);
} non funziona pk se ce una lista vuota */

void show(Node* f){//ver iterativa
    while(f){
       
        f=f->next;}
    
}

void show(Node*f){//ver ricorsiva
     if(f){printf("%d\n",f->key);
        show(f->next);
        
    }
}

Node* add(int key,Node*f){//key nuova chiave da aggiungere alla lista e poi la lista da cui aggiungo
    //restitiuisce il nuovo valore del primo elemento della lista 
    // più utilie aggiungere un elemento dalla testa complessità 1(un passaggio)
    //se si aggiunge una lista in coda bisogna utilizzare n passaggi pk bisogna scorrere la lista 

// da fare a casa 
}//push add degli stack
//delete node da fare a casa 


Node * delete(Node*f,int*key){
    *key=f->key;
    Node*ret=f->next;
    free(f);
    return ret;
}//cancella il primo elemento //pop delete dello stack
//restituisce anche key ciò la chiave del nodo che ha cancellato 


int main(){
    Node n;
    n.a=3;
    n.b=10;

    Node*pa=(Node*)malloc(sizeof(Node)) ;
    Node* first=NULL;
    first=createNode(42,NULL);//crea la struct e popola i campi(come la solita create)
    second=createNode(57,NULL);
    setNext(first,second);//setta il nuovo valore di next = second
    //per avere una lista vuota basta settare first a null se first è diverso da null ce almeno un elemento nella lista 
    first=add(53,first);
    int value;
    first=delete(first,&value);
return 0;
}