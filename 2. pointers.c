#include <stdio.h>

int main(){
int a,b,x;
int *p,*h;

printf("Ingresa los valores de A y B\n");
printf("A: ");
scanf("%d",&a);
printf("B: ");
scanf("%d",&b);

p=&a;
h=&b;
x=a;
*p=b;
*h=x;

printf("El valor de A es: %d\n",*p);
printf("El valor de B es: %d\n",*h);
}
