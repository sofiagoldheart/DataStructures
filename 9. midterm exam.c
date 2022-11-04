//Sofia Ruvalcaba de la Noval. 210300529. Examen 2do Parcial.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
    int number, loc;
    struct node *next; 
    struct node *prev;
};

struct node *head, *tail, *new, *aux;

void binary();
void decimal();
void delete();

int main(){
    head=NULL;
    tail=NULL;
    int op=0;
    do{
        puts("");
        puts("---");
        puts("Seleccione una opcion del menu:");
        puts("1. Decimal a binario.");
        puts("2. Binario a decimal.");
        puts("3. Salir.");
        puts("---");
        scanf("%d", &op);
        puts("---");
    switch(op){
        case 1:
            binary();
            break;
        case 2:
            decimal();
            break;
        case 3:
            return 0;
            break;
        }
    } while(op!=3);
    return 0;
}

void binary()
{
    int dec=0;
    puts("Introduzca el numero decimal:");
    scanf("%d", &dec);
    do{
        new = (struct node *)malloc(sizeof(struct node));
        if(new==NULL){
            puts("No se reservo memoria");
            break;
        }
            new->number = dec % 2;
            new->prev = NULL;
            new->next = NULL;
        if (head==NULL){
            head=new;
            tail=new;
        } else {
            new->next=head;
            head->prev=new;
            head=new;
        }
        dec = dec / 2;
    } while(dec!=0);
        aux=head;
        puts("Numero binario:");
    while(aux!=NULL){
        printf("%d", aux->number);
        aux=aux->next;
    }
    delete();
}

void decimal()
{
    char bin[25];
    puts("Introduzca el numero binario:");
    scanf("%s", bin);
    for(int i=0; bin[i]!='\0'; i++){
        if(bin[i]!='0' && bin[i]!='1'){
            puts("Error, ingrese solo 0 o 1 en su valor. Intente nuevamente.");
            scanf("%s", bin);
            i=0;
        }
    }
    for(int i=0; bin[i]!='\0'; i++){
        new = (struct node*)malloc(sizeof(struct node));
        if(new==NULL){
            puts("No se reservo memoria");
            break;
        }
        if(bin[i]=='1'){
            new->number=1;
        }else if(bin[i]=='0'){
            new->number=0;
        }
        new->prev=NULL;
        new->next=NULL;
        if(head==NULL){
            head=new;
            tail=new;
        }
        else{
            new->next=head;
            head->prev=new;
            head=new;
        }
    }
    aux=head;
    for(int i=0;aux!=NULL;i++){
        aux->loc = i;
        aux=aux->next;
    }
    aux=head;
    do{
        aux->number = aux->number*pow(2, aux->loc);
        aux=aux->next;
    }while(aux!=NULL);
    int dec=0;
    aux=head;
    do{
        dec = dec + aux->number;
        aux=aux->next;
    }while(aux!=NULL);
    puts("Numero decimal:");
    printf("%d", dec);
    delete();
}

void delete()
{
    while(head!=NULL){
        aux=head;
        if(head==tail){
            tail=NULL;
            head=NULL;
            free(aux);
            break;
    }else{
            head=head->next;
            head->prev=NULL;
            aux->prev=NULL;
            aux->next=NULL;
            free(aux);
        }
    }
}
