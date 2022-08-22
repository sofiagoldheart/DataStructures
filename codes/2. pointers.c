#include <stdio.h>
//Definir las variable entera a y el apuntador y.
int a;
int *y;

int main(){
//Guardar valor de a con 5 y el de y con dirección de memoria de a.
a=5;
y=&a;

//Imprimir el valor de a y y.
printf("El valor de la variable es %d\n",a);
printf("El valor del puntero es %p",y);

return 0;
}
