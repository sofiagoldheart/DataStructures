//Arbol Binario - Sofia Ruvalcaba de la Noval
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *new(int data)
{
    struct node *nuevo;
    nuevo = (struct node *) malloc(sizeof(struct node));
    nuevo->data = data;
    nuevo->left = NULL;
    nuevo->right = NULL;
    return nuevo; 
}

void insertar(struct node *nuevo,int data) 
{
    if(nuevo->data<data){
        if(nuevo->right == NULL){
            nuevo->right=new(data);
        }else{
            insertar(nuevo->right,data);
        }
    }else{
        if(nuevo->left == NULL){
            nuevo->left =new(data);
        }else{
            insertar(nuevo->left, data);
        }
    }
}

void Preorder (struct node *node)
{
    if (node != NULL){
        printf("%d -> ",node->data);
        Preorder(node->left);
        Preorder(node->right);
    }
}

void Inorder(struct node* node)
{
    if (node != NULL){
        Inorder(node->left);
        printf("%d -> ", node->data);
        Inorder(node->right);
    }
}

void Postorder(struct node* node)
{
    if (node != NULL){
        Postorder(node->left);
        Postorder(node->right);
        printf("%d -> ", node->data);
    }
}

int main(){
    int op, data;
    struct node *tree = NULL;
    do{
        puts("   ");
        puts("Seleccione una opcion del menu:");
        puts("1. Ingresar");
        puts("2. Mostrar Preorder");
        puts("3. Mostrar Inorder");
        puts("4. Mostrar Postorder");
        puts("5. Salir.");
        puts("-----------");
        scanf("%d", &op);
        puts("-----------");
    switch(op){
    case 1:
        puts("Ingresar el dato:");
        scanf("%d",&data);
        if (tree==NULL){
            tree = new (data);
        }else{
            insertar(tree,data);
        }
        break;
    case 2:
        if(tree==NULL){
            puts("Vacio");
        } else {
            Preorder(tree);
        }
        break;
    case 3:
        if(tree==NULL){
            puts("Vacio");
        } else {
            Inorder(tree);
        }
        break;
    case 4:
        if(tree==NULL){
            puts("Vacio");
        } else {
            Postorder(tree);
        }   
        break;
    case 5:
    return 0;
        break;
        }
    } while(op!=5);
    return 0;
}
