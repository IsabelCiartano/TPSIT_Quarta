typedef struct{
    char* nome;
    int numero;
    struct node* next;
}node;

int main(){
    node* head=(node*)malloc(sizeof(node));
    head->next=NULL;
    node* el1=(node*)malloc(sizeof(node));
    el1->nome="isa";
    el1->numero=3517063960;
    head->next=el1;
    el1->next=NULL;



    return 0;

}