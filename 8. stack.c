/*Desarrolla una pila dinámica en C. Debes utilizar funciones (25pts)
Menú:
1. Insertar elemento (25 pts) Push
2. Visualizar Pila (25 pts)
3. Eliminar elemento (25 pts) Pop
4. Salir
SOFIA RUVALCABA DE LA NOVAL - 210300529.
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void display();
void push(int);
void pop();

int main(){
    int n, op;
    do{
        puts("-----------");
        puts("Seleccione una opcion del menu:");
        puts("1. Insertar elemento.");
        puts("2. Visualizar pila.");
        puts("3. Eliminar elemento.");
        puts("4. Salir.");
        puts("-----------");
        scanf("%d", &op);
        puts("-----------");
    switch(op){
        case 1:
            puts("Ingrese un numero:");
            scanf("%d", &n);
            push(n);
            break;
        case 2:
            display();
            break;
        case 3:
            pop();
            break;
        case 4:
            return 0;
        break;
        }
    } while(op!=0);
    return 0;
}   

void push(int item)
{
    struct node *nptr = malloc(sizeof(struct node));
    nptr->data = item;
    nptr->next = top;
    top = nptr;
}

void display()
{
    struct node *temp;
    temp = top;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void pop()
{
    if (top == NULL)
    {
        puts("La pila esta vacia.");
    }
    else
    {
        struct node *temp;
        temp = top;
        top = top->next;
        printf("%d fue eliminado\n", temp->data);
        free(temp);
    }
}
