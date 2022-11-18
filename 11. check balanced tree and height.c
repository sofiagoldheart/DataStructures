//Arbol Binario - Sofia Ruvalcaba de la Noval
#include <stdio.h>
#include <stdlib.h>
#define bool int

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

void insert(struct node *nuevo, int data) 
{
    if(nuevo->data<data){
        if(nuevo->right == NULL){
            nuevo->right = new(data);
        }else{
            insert(nuevo->right,data);
        }
    }else{
        if(nuevo->left == NULL){
            nuevo->left = new(data);
        }else{
            insert(nuevo->left, data);
        }
    }
}

void preorder (struct node *node)
{
    if (node != NULL){
        printf("%d -> ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(struct node* node)
{
    if (node != NULL){
        inorder(node->left);
        printf("%d -> ", node->data);
        inorder(node->right);
    }
}

void postorder(struct node* node)
{
    if (node != NULL){
        postorder(node->left);
        postorder(node->right);
        printf("%d -> ", node->data);
    }
}

bool balance(struct node *node, int *height) {
  int lefth = 0, righth = 0;
  int l = 0, r = 0;
    if (node == NULL) {
        *height = 0;
        return 1;
    }
  l = balance(node->left, &lefth);
  r = balance(node->right, &righth);
  *height = (lefth > righth ? lefth : righth) + 1;
    if ((lefth - righth >= 2) || (righth - lefth >= 2)){
        return 0;
    } else {
    return l && r;
    }
}

int level(struct node *node){
    int hleft, hright;
    if(node == NULL){
        return 0;
    } else {
        hleft = level(node->left);
        hright = level(node->right);}
    if(hleft>hright){
        return hleft+ 1;
    } else {
        return hright+ 1;  
    }
}

int main(){
    int op, data, h;
    int height = 0;
    struct node *tree = NULL;
    do{
        puts("   ");
        puts("Seleccione una opcion del menu:");
        puts("1. Ingresar");
        puts("2. Mostrar Preorder");
        puts("3. Mostrar Inorder");
        puts("4. Mostrar Postorder");
        puts("5. Balanceado y Nivel");
        puts("6. Salir.");
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
            insert(tree,data);
        }
        break;
    case 2:
        if(tree==NULL){
            puts("Vacio");
        } else {
            preorder(tree);
        }
        break;
    case 3:
        if(tree==NULL){
            puts("Vacio");
        } else {
            inorder(tree);
        }
        break;
    case 4:
        if(tree==NULL){
            puts("Vacio");
        } else {
            postorder(tree);
        }   
        break;
    case 5:
        if (balance(tree, &height)){
        puts("El arbol esta balanceado");
        } else {
        puts("El arbol no esta balanceado");   
        }
        h = level(tree);
        printf("El arbol tiene un nivel de: %d",h);
        break;
    case 6:
        return 0;
        break;
        }
    } while(op!=6);
    return 0;
}
