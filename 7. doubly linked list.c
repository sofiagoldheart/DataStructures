//Sofia Ruvalcaba de la Noval. 210300529. Lista Doblemente Enlazada.
#include <stdio.h>  
#include <stdlib.h>  
typedef struct node  
{  
    int folio, edad;
    char nombre[15];
    float promedio;
    struct node *next; 
    struct node *prev;   
}node;  

node* head = NULL;
node* tail = NULL;
node* new;

void insert_left();
void insert_right();  
void display_full();
void display_inverted();
void search();
void modify();
void delete();  
void data(node *temp);

int main(){
    int op=0;
    do{
        puts("---");
        puts("Seleccione una opcion del menu.");
        puts("1. Insertar elemento a la izquierda.");
        puts("2. Insertar elemento a la derecha.");
        puts("3. Visualizar lista completa.");
        puts("4. Visualizar lista invertidad.");
        puts("5. Buscar elemento de la lista.");
        puts("6. Modificar elemento de la lista.");
        puts("7. Eliminar elemento de la  lista.");
        puts("8. Salir");
        puts("---");
        scanf("%d", &op);
        puts("---");
    switch(op){
    case 1:
        insert_left();
        break;
    case 2:
        insert_right();
        break;
    case 3:
        display_full();
        break;
    case 4:
        display_inverted();
        break;
    case 5:
        search();
        break;
    case 6:
        modify();
        break;
    case 7:
        delete();
        break;
    case 8:
        return 0;
        break;
    }
    } while(op!=8);
    return 0;
}

void insert_left()  
{  
    struct node *new,*temp;  
    int folio;  
    new = (struct node*) malloc(sizeof(struct node));  
    if(new == NULL){  
        puts("No se reservo memoria");   
    }  
    data(new);
    new->next = NULL;
    if(head == NULL){
        head = new;
        head->next = NULL;
        head->prev = NULL;
        tail = head; 
    }else if(head->next == NULL){
        head->prev = new;
        new->next = head;
        head = new;   
    }else{
        new->prev = tail->prev;
        new->next = tail;
        tail->prev->next = new;
        tail->prev = new;    
    }
    puts("Datos ingresados correctamente");  
}  


void insert_right()  
{  
    struct node *new;   
    int folio;
    new = (struct node*)malloc(sizeof(struct node));  
    if(new == NULL){  
       puts("No se reservo memoria");  
    }  
    data(new);
    if(head == NULL){
        head = new;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }else{
        tail->next = new; 
        new->next = NULL;
        new->prev = tail;
        tail = new;
    }
    puts("Datos ingresados correctamente");          
}

void display_full()  
{  
    int i=1;
    struct node *aux;
    aux = head;
    while(aux!=NULL){
        printf("Los datos del folio no. %d ingresado son: \n",i);
        printf("Folio: %i\n", aux->folio);
        printf("Nombre: %s\n", aux->nombre);
        printf("Edad: %i\n", aux->edad);
        printf("Promedio: %.2f\n", aux->promedio);
        printf("\n");
        aux=aux->next;
        i++;
    }
}
    
void display_inverted()
{  
    int i=1;
    struct node *aux;
    aux = tail;   
    while(aux != NULL) {        
        printf("Los datos del folio no. %d ingresado son: \n",i);
        printf("Folio: %i\n", aux->folio);
        printf("Nombre: %s\n", aux->nombre);
        printf("Edad: %i\n", aux->edad);
        printf("Promedio: %.2f\n", aux->promedio);
        printf("\n");
        aux = aux->prev;
        i++;
   }
}

void search()
{  
    struct node *ptr;  
    ptr = head;
    int find = 0, flag = 0;
    puts("Ingrese el folio que desea buscar:");
    scanf("%d", &find);
    if(head != NULL){
        while(ptr != NULL && flag != 1){
            if(ptr->folio == find){
                printf("El registro con el folio (%d) es: \n", find);
                flag = 1;
                printf("El nombre es: %s \n", ptr->nombre);
                printf("La edad es: %d \n", ptr->edad);
                printf("El promedio es: %2.f \n", ptr->promedio);
            }
                ptr = ptr->next;
        }  
        if(flag == 0){
            puts("El folio ingresado no existe.");
        }
        }else{
        puts("Lista vacia");
    }
}  

void modify()
{
    struct node *ptr;  
    ptr = head;
    int find = 0, flag = 0;
    puts("Ingrese el folio que desea modificar:");
    scanf("%d", &find);
    if(head != NULL){
        while(ptr != NULL && flag != 1){
            if(ptr->folio == find){
                printf("El registro con el folio (%d) es: \n", find);
                data(ptr); 
                puts("Datos modificados con exito");
                flag = 1; 
            }
            ptr = ptr->next;
        }  
        if(flag == 0){
            puts("El folio ingresado no existe.");
        }
        }else{
        puts("Lista vacia");
    }
}
 
void delete()  
{  
    struct node *ptr, *temp;  
    int folio, flag = 0;
    do{
        ptr = head;
        puts("Ingrese el folio que desea eliminar:");
        scanf("%d",&folio);
    if(head->folio == folio){
        temp = head->next;
        head = NULL;
        head = temp; 
        flag = 1;
        break;
        }
    while(ptr->next != NULL){
        if(ptr->next->next == NULL){
            if(ptr->next->folio == folio){
                tail = ptr;
                ptr->next = NULL;
                flag = 1;
                break;
            }else{
            puts("El folio ingresado no existe.");
            }  
        }
        if(ptr->next->folio == folio){
            temp = ptr->next->next;
            ptr->next = NULL;
            ptr->next = temp;
            flag = 1;
            break;
        }
            ptr = ptr->next;
    }    
    }while(flag == 0); 
}

void data(node* temp){
    struct node *aux;
    if(head != NULL){
    do{
        aux = head;
        puts("Ingresa el folio:");
        scanf("%d", &temp->folio);
    while(aux != NULL){
        if(temp->folio == aux->folio && aux != temp){
            break;
        }else if(aux->next == NULL){
            break;
        }else{
            aux = aux->next;
        }
    }
        if(temp->folio == aux->folio){
            puts("Datos ingresados incorrectamente, intente de nuevo.");
        }
        }while(temp->folio == aux->folio);  
        }else{
            puts("Ingresa el folio:");
            scanf("%d", &temp->folio);
        }
            puts("Ingresa el nombre:");
            scanf("%s", temp->nombre);
        do{
            puts("Ingresa la edad:");
            scanf("%d", &temp->edad);
        if(temp->edad < 0 || temp->edad > 99){
            puts("Datos ingresados incorrectamente, intente de nuevo.");
        }
        }while(temp->edad < 0 || temp->edad > 99);
        do{
            puts("Ingresa el promedio:");
            scanf("%f", &temp->promedio);
        if(temp->promedio < 0 || temp->promedio > 10){
            puts("Datos ingresados incorrectamente, intente de nuevo.");
        }
        }while(temp->promedio < 0 || temp->promedio > 10);
}
