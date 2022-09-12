#include <stdio.h>
#include <string.h>

 struct alumnos{
    char nombre [20];
    int edad;
    float estatura; 
};
struct alumnos personas [3];

int main(){
struct alumnos *pointer;
pointer=&personas[0];
    for(int i=0; i<=2; i++){
puts("Ingresa tu nombre:");
scanf("%s",pointer->nombre);
puts("Ingresa tu edad:");
scanf("%d",&pointer->edad);
puts("Ingresa tu estatura:");
scanf("%f",&pointer->estatura);
printf("Tu nombre es %s\n",pointer->nombre);
printf("Tu edad es %d\n",pointer->edad);
printf("Tu estatura es %.2f\n",pointer->estatura);
}    
}
