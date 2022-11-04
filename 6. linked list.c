//lista simple. por sofia ruvalcaba de la noval. 210300529.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct agenda{
    char name[15];
    int folio, age;
    float average;
    struct agenda *next;
    };

struct agenda *first;
struct agenda *last;

void insertar();
void visualizar();
void buscar();
void modificar();
void eliminar();

int main(){
    int op=0;
    first=NULL;
    last=NULL;
    do{
        puts("---");
        puts("Seleccione una opcion del menu:");
        puts("1. Insertar elemento a la lista");
        puts("2. Visualizar lista completa");
        puts("3. Buscar elemento de la lista");
        puts("4. Modificar elemento de la lista");
        puts("5. Eliminar elemento de la lista");
        puts("6. Salir");
        puts("---");
        scanf("%d", &op);
        puts("---");
    switch(op){
        case 1:
            insertar();
        break;
        case 2:
            visualizar();
        break;
        case 3:
            buscar();
        break;
        case 4:
            modificar();
        break;
        case 5:
            eliminar();
        break;
        case 6:
            return 0;
        break;
    }
    } while(op!=6);
    return 0;
}

void insertar(){
    struct agenda *new;
    new = NULL;
    new = (struct agenda *) malloc (sizeof(struct agenda));
    if(new == NULL){
        printf("No se reservo memoria");
        }
        puts("Inserta el folio:");
        scanf("%d",&new->folio);
        puts("Inserta el nombre:");
        scanf("%s",new->name);
        puts("Inserta la edad:");
        scanf("%d",&new->age);
        puts("Inserta el promedio:");
        scanf("%f",&new->average);
            new->next=NULL;
    if (first == NULL){
        first = new;
        last = new;
    }else{
        last -> next = new;
        last = new;
            }
}

void visualizar(){
    int i=1;
    struct agenda *aux;
    aux=first;
    while(aux!=NULL){
        printf("Los datos del folio no. %d ingresado son: \n",i);
        printf("Folio: %i\n", aux->folio);
        printf("Nombre: %s\n", aux->name);
        printf("Edad: %i\n", aux->age);
        printf("Promedio: %.2f\n", aux->average);
        printf("\n");
        aux=aux->next;
        i++;
    }
}

void buscar(){
    int searchfolio;
    struct agenda *aux;
    aux=first;
    puts("Ingresa el folio a buscar:");
    scanf("%i",&searchfolio);
    while (aux!=NULL){
        if(aux->folio==searchfolio){
        printf("\n");
        printf("Los datos del folio que ha buscado son: \n");
        printf("Nombre: %s\n", aux->name);
        printf("Edad: %i\n", aux->age);
        printf("Promedio: %.2f\n", aux->average);
        }
        aux=aux->next;
    }
}

void modificar(){
    int modfolio;
    struct agenda *aux;
    aux=first;
    puts("Ingresa el folio a modificar:");
    scanf("%i",&modfolio);
    while(aux!=NULL){
        if(aux->folio==modfolio){
        printf("\n");
        puts("Ingresa el nuevo folio:");
        scanf("%i",&aux->folio);
        puts("Ingresa el nuevo nombre:");
        scanf("%s",aux->name); 
        puts("Ingresa la nueva edad:");
        scanf("%i",&aux->age); 
        puts("Ingresa el nuevo promedio:");
        scanf("%.2f",&aux->average);
        }
        aux = aux->next;
    } 
}

void eliminar(){
    struct agenda *aux, *move;
    struct agenda *next;
    int delfolio, found, notfound; 
    int opdelete;
    do{
        found = 0;
        aux = first; 
        puts("Ingresa el folio a eliminar:");
        scanf("%i",&delfolio);
    while (aux != NULL){
        if (first -> folio == delfolio){
            move = first -> next;
            first = NULL;
            first = move;
            found = 1;
            break;
        } else if (delfolio == aux -> next -> folio){
        if (aux -> next -> next == NULL){
            last = aux;
            aux -> next = NULL;
        } else {
          move = aux -> next -> next;
          aux -> next = NULL;
          aux -> next = move;
        }
        found = 1;
        break;
        } else if (aux -> next == NULL){
        printf ("Folio no encontrado\n");
        break;
        }
        aux = aux -> next;
        }   
        } while (found != 1);  
} 
