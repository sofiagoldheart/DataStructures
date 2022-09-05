#include <stdio.h>
#include <string.h>

 struct alumnos
 {
    int matricula, edad;
    char nombre [20];
    float promedio; 
};

struct alumnos p;
int edad(int edad);
float promedio(float promedio);

int main(){
    int n=0;
    printf ("Ingresa la cantidad de registros a guardar: ");
    scanf ("%d", &n);

struct alumnos datos[n];
    for(int i=0; i<n; i++){
         printf ("Ingresa la matricula no. %d: ",i+1);
    scanf ("%d", &datos[i].matricula);

    printf ("Ingresa el nombre no. %d: ",i+1);
    scanf ("%s", &datos[i].nombre);
    datos[i].edad=edad(datos[i].edad);
    datos[i].promedio=promedio(datos[i].promedio);
    }
     for(int i=0; i<n; i++){
        printf("\nAlumno no. %d:", i+1);
        printf("\nMatricula no. %d: %d", i+1, datos[i].matricula);
        printf("\nNombre no. %d: %s", i+1, datos[i].nombre);
        printf("\nEdad no. %d: %d", i+1, datos[i].edad);
        printf("\nPromedio no. %d: %f", i+1, datos[i].promedio);
    }
    }

int edad(int edad){
    do{
        printf("Inserte la edad:");
        scanf("%d", &edad);
    }
    while(edad<18 || edad>99);
    return edad;
}

float promedio(float promedio){
    do{
        printf("Inserte el promedio:");
        scanf("%f", &promedio);
    }
    while(promedio<0.0 || promedio>10.0);
    return promedio;
}