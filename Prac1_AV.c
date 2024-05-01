#include <stdio.h>
#include <string.h>
/*Programar en ANSI C, cada una de las siguientes operaciones
 - Longitud
 - Concatenación
 ----- Parte de desarrollo de Angel Vega
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Documentación:
 Nombre(s) :
        Jose Angel Vega Reyes

 # Boleta: 2021630030
 Equipo 5 | Teoría de la computación
 Práctica 1.*/

// Definición de macrodefinicones;
#define MAX_LON_CAD 50
// Variables globales;
char A[MAX_LON_CAD], B[MAX_LON_CAD], c[2], a, b;
int l, i, n;
int main()
{
    printf("1.- Longitud\n");
    printf("2.- Concatenacion\n");
    scanf("%d", &l);
    switch (l)
    {
    case 1:
    {
        printf("Ingrese Cadena A:\n");
        scanf("%s", &A);
        for (i = strlen(A) - 1; i >= 0; i--)
        {
            a = A[i];
            if (a == '1' || a == '0')
            {
                a = A;
            }
            else
            {
                printf("La cadena  A no es binaria\n");
                return 0;
            }
        }
        printf("Ingrese Cadena B:\n");
        scanf("%s", &B);
        for (n = strlen(B) - 1; n >= 0; n--)
        {
            b = B[n];
            if (b == '1' || b == '0')
            {
                b = B;
            }
            else
            {
                printf("La cadena B no es binaria\n");
                return 0;
            }
        }
        printf("La longitud de A es: %d\n", strlen(A));
        printf("La longitud de B es: %d\n", strlen(B));
    }
    break;
    case 2:
    {
        printf("Ingresa la cadena A:\n");
        scanf("%s", A);
        for (i = strlen(A) - 1; i >= 0; i--)
        {
            a = A[i];
            if (a == '1' || a == '0')
            {
                a = A;
            }
            else
            {
                printf("La cadena  A no es binaria\n");
                return 0;
            }
        }
        printf("\nIngresa la cadena B:\n");
        scanf("%s", B);
        for (n = strlen(B) - 1; n >= 0; n--)
        {
            b = B[n];
            if (b == '1' || b == '0')
            {
                b = B;
            }
            else
            {
                printf("La cadena B no es binaria\n");
                return 0;
            }
        }
        printf("\nLa cadena concatenada es: %s\n", strcat(A, B));
    }
    default:
    {
        return 0;
    }
    break;
    }
    return 0;
}