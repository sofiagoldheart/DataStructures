//Examen Primer Parcial Sofia Ruvalcaba de la Noval.
#include <stdio.h>
#include <string.h>

struct alumnos{
    char nombre [20];
    char matricula[10];
    int edad;
    float promedio; 
};

//Arreglo de estructuras de 5 elementos.
struct alumnos personas[5];

//Función para la verificación de la edad. 
int edad(int edad){
    do{
        puts("Ingrese su edad: ");
        scanf("%d", &edad);
    }
    while(edad<18 || edad>99);
    return edad;
}
//Función para la verificación del promedio.
float promedio(float promedio){
    do{
        puts("Inserte su promedio:");
        scanf("%f", &promedio);
    }
    while(promedio<0.0 || promedio>10.0);
    return promedio;
}
//Función para modificar matrícula.
void cambiarmatricula ( struct alumnos *pointer, char *matricula){ 
        printf("%s", matricula);
        printf("%s", pointer[0].matricula);
    for (int i = 0; i < 1; i++){
        if (strcmp(pointer[i].matricula,matricula)==0){
            puts("\n+++");
            strcpy(pointer[i].matricula, matricula);
            puts("\nIngrese su nombre: ");
            scanf("%s",pointer[i].nombre);
            pointer[i].edad=edad(pointer[i].edad);
            pointer[i].promedio=promedio(pointer[i].promedio); 
            puts("\n+++");
        } 
    }
}
//Función para eliminar datos.
void eliminarmatricula ( struct alumnos *pointer, char *matricula){
    for (int i = 0; i < 5; i++){
        if (strcmp(pointer[i].matricula,matricula)==0){
            if (pointer[i+1].matricula != NULL){
                pointer[i] = pointer[i+1];
            }
            else {
                i-= 1;
            }
        }
    }
}

int main(){
    int i=0, op=0, f=0;
    struct alumnos *pointer;
        pointer=&personas[0];
    do{
        //Menú:
        puts("---");
        printf("Seleccione una opcion:\n");
        printf("1- Ingresar datos\n");
        printf("2- Visualizar todos los datos\n");
        printf("3- Modificar una matricula\n");
        printf("4- Eliminar una matricula\n");
        printf("5- Salir\n");
        puts("---");
        scanf("%d", &op);
        puts("---");
        switch(op){ 
            case 1: 
            //Insertar datos:
                for(int i=0; i<5; i++){  
                  puts("Introduzca su matricula:");
                  char matricula[20];
                  scanf("%20s", matricula);
                  //Bucle para que el valor de la matrícula no se repita.
                  for (int j = 0; j < 5; j++){
                        printf("%s", pointer[j].matricula); 
                        if (strcmp(pointer[j].matricula, matricula) == 0){
                        puts("ERROR,");
                        puts("Introduzca nuevamente su matricula:");
                        scanf("%20s", matricula);
                        break;
                        }
                  }
                        strcpy(pointer[i].matricula, matricula);
                        puts("\nIngrese su nombre: ");
                        scanf("%s",pointer[i].nombre);
                        pointer[i].edad=edad(pointer[i].edad);
                        pointer[i].promedio=promedio(pointer[i].promedio); 
                        puts("---");
                    }
                continue;
            break;

            case 2:
            //Visualizar datos.
              for(int i=0; i<5; i++){
                    puts("---");
                printf("DATOS DEL ALUMNO: %i\n", i + 1); 
                printf("Matricula: %s\n", pointer[i].matricula);
                printf("Nombre: %s\n", pointer[i].nombre);
                printf("Edad: %i\n",pointer[i].edad);
                printf("Promedio: %.2f\n", pointer[i].promedio);
                    puts("---");
                }   
                continue;
            break;

            case 3:
            //Modificar datos.
                puts("Inserte matricula a cambiar:");
                char matricula[20];
                scanf("%20s", matricula);

                cambiarmatricula(pointer, matricula);
                continue;
            break;

            case 4:
            //Eliminar datos:
                puts("Inserte matricula a eliminar:");
                scanf("%20s", matricula);
                eliminarmatricula(pointer, matricula);
            break;
                
            case 5:
            //Salir:
            return 0;
            break;

            default:
                printf("\nOpcion invalida\n");
            break;
            } 
    } while(op!=5);
    return 0;
}
