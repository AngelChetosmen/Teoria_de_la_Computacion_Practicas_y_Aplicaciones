#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Definición de macrodefinicones;
#define MAXIMA_LONGITUD_CADENA 100
#define MAX_LON_CAD 50
char A[MAX_LON_CAD], B[MAX_LON_CAD], C[MAX_LON_CAD], a, *f1, *f2;
// Modulos
void potencia(char cadena[], int potencia);
void inverso(char cadena[]);
void comprobacion(char C[MAX_LON_CAD]);
// Variables globales;
int pot, i, prefijo = 0;
int main()
{
    int opcion = 1, opcionOperacion = 0;
    while (opcion == 1)
    {
        printf("Ejercicios con cadenas \n \n"
               "Elige una de las siguientes opciones: \n"
               "1. Longitud       4. Inverso\n"
               "2. Concatenacion  5. Prefijos\n"
               "3. Potencia       6. Sujifos\n"
               "4. Inverso        7. Subcadenas\n"
               "5. Prefijos       8. Salir\n"
               "\n Opcion: ");
        scanf("%d", &opcionOperacion);
        system("cls");
        switch (opcionOperacion)
        {
        case 1:
        {
            printf("Ingrese Cadena A:\n");
            scanf("%s", &A);
            comprobacion(A);
            printf("Ingrese Cadena B:\n");
            scanf("%s", &B);
            comprobacion(B);
            printf("La longitud de A es: %d\n", strlen(A));
            printf("La longitud de B es: %d\n", strlen(B));
        }
        break;
        case 2:
        {
            printf("Ingresa la cadena A:\n");
            scanf("%s", A);
            comprobacion(A);
            printf("\nIngresa la cadena B:\n");
            scanf("%s", B);
            comprobacion(B);
            printf("\nLa cadena concatenada es: %s\n", strcat(A, B));
            break;
        }
        case 3:
        {
            printf("Ingrese Cadena A:\n");
            scanf("%s", A);
            comprobacion(A);
            printf("Escoja la potencia :");
            scanf("%d", &pot);
            potencia(A, pot);
        }
        break;
        case 4:
        {
            printf("Ingrese Cadena A:\n");
            scanf("%s", A);
            comprobacion(A);
            inverso(A);
        }
        break;
        case 5:
        {
            printf("Ingresa la primer cadena \n");
            fflush(stdin);
            scanf("%[^\n]", A);
            f1 = A;
            printf("La frase introducida fue: %s\n", A);
            comprobacion(A);
            fflush(stdin);
            printf("Ingresa la segunda cadena \n");
            fflush(stdin);
            scanf("%[^\n]", B);
            f2 = B;
            printf("La frase introducida fue: %s\n", B);
            comprobacion(B);
            f1 = A;
            f2 = B; // para condicionales se puede hacer otro void
            if (strcmp(A, B) == 0)
            {
                printf("Las cadenas son iguales");
            }
            else if (*f1 != *f2 && prefijo == 0)
            {
                printf("La cadena son diferentes");
            }
            else
            {
                while (*f1 == *f2)
                {
                    prefijo++;
                    f1++;
                    f2++;
                }
                int inicio = 0;
                char extraida[MAXIMA_LONGITUD_CADENA] = "";
                strncpy(extraida, A + inicio, prefijo);
                printf("El prefijo es : '%s'\n", extraida);
            }
        }
        break;
        case 8:
            exit(0);
            break;
        default:
            exit(0);
        }
        printf("\n\nDeseas realizar otra operacion? (1/0) Si = 1 y NO = 0: ");
        scanf("%d", &opcion);
        system("cls");
    }
    return 0;
}
// Modulo Potencia
void potencia(char cadena[], int potencia)
{
    int pote, i1 = 0, m = 0, j = 0;
    char cade1[MAX_LON_CAD], cadcop[MAX_LON_CAD];
    while (cadena[i1] != '\0')
    {
        cade1[i1] = cadena[i1];
        i1++;
    }
    cade1[i1] = '\0';
    pote = potencia;
    i1 = 0;
    while (cade1[i1] != '\0')
    {
        cadcop[i1] = cade1[i1];
        i1++;
    }
    j = i1;
    for (m = 1; m < pote; m++)
    {
        i1 = 0;
        while (cade1[i1] != '\0')
        {
            cadcop[j] = cade1[i1];
            i1++;
            j++;
        }
    }
    cadcop[j] = '\0';
    printf("\n%s", cadcop);
    printf("\n\n");
}
// Modulo Inverso
void inverso(char cadena[])
{
    int lo, i1, j;
    char aux[MAX_LON_CAD];
    memset(aux, 0, MAX_LON_CAD);
    lo = strlen(cadena);
    j = lo - 1;
    for (i1 = 0; i1 < lo; i1++)
    {
        aux[j] = cadena[i1];
        j--;
    }
    printf("Cadena invertida:\n%s\n", aux);
}
// Modulo de comprobacion
void comprobacion(char C[MAX_LON_CAD])
{
    for (i = strlen(C) - 1; i >= 0; i--)
    {
        a = C[i];
        if (a == '1' || a == '0')
        {
            a = C;
        }
        else
        {
            printf("La ultima cadena que se ingreso no es binaria\n");
            system("pause");
            exit(a = 0);
        }
    }
    /* Otro modo de comprobar que una cadena sea binaria
    primero es declarar char * f2, frase2[tamañodelarray]; luego
    f2 = frase2;
    se pedira -> "scanf("%[^\n]", frase2);", despues se puede poner el siguiente código
    o realizar un void y llamarlo:
    while (*f2 != '\0'){
        if (*f2 == '0' || *f2 == '1'){
            f2++;
        }else{
            printf("La cadena no es binaria");
            // return 0;}        }
    }
    //codigo simplificao en líneas(no esta bien identado*);
    */
}