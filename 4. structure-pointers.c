#include <stdio.h>
#include <string.h>

 struct alumnos{
    char nombre [20];
    int edad;
    float estatura; 
};
struct alumnos personas;

int main(){
struct alumnos *pointer;
pointer=&personas;
puts("Ingresa tu nombre:");
scanf("%s",pointer->nombre);
puts("Ingresa tu edad:");
scanf("%d",&pointer->edad);
puts("Ingresa tu estatura:");
scanf("%f",&pointer->estatura);

printf("Tu nombre es %s\n", pointer->nombre);
printf("Tu edad es %d\n", pointer->edad);
printf("Tu estatura es %.2f", pointer->estatura);
}
