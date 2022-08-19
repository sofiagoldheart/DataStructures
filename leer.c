#include <stdio.h>
    struct persona{
    char nombre [10];
    int edad;
    float peso;
    };

struct persona p;

int main(){
    scanf ("%s", &p.nombre);
    scanf ("%d", &p.edad);
    scanf ("%f", &p.peso);

    printf("%s",p.nombre);
    printf("%d",p.edad);
    printf("%.2f",p.peso);

return 0;
}
