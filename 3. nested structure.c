#include <stdio.h>
#include <string.h>
//Sofia Ruvalcaba de la Noval, 210300529, Estructras anidadas. Decidí hacer el código en inglés por temor a que hubiera algún problema con "año" por la ñ.

//estructura de fecha de nacimiento
struct birthdate
{
    int day;
    int month;
    int year;
};
//estructura principal
struct students
{
    int id;
    char name [20];
    struct birthdate bd;
};

int main()
{
    struct students st;
    
    puts("Ingresa la matricula:");
    scanf("%d",&st.id);
    puts("Ingresa el nombre:");
    scanf("%s",st.name);
    puts("Ingresa la fecha de nacimiento:");
    scanf("%d%d%d",&st.bd.day,&st.bd.month,&st.bd.year);

    printf("Matricula: %d\n",st.id);
    printf("Nombre: %s\n",st.name);
    printf("Fecha de nacimiento: %d-%d-%d\n",st.bd.day,st.bd.month,st.bd.year);
}
