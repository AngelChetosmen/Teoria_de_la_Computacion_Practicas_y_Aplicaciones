#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Definición de macrodefinicones;
#define MAXIMA_LONGITUD_CADENA 100
#define MAX_LON_CAD 50
char A[MAX_LON_CAD], B[MAX_LON_CAD], c[2], a, b;
// Modulos
void potencia(char cadena[], int potencia);
void inverso(char cadena[]);
// Variables globales;
int l, i, n;
int main()
{
    int opcion = 1, opcionOperacion = 0;
    while (opcion == 1)
    {
        printf("Ejercicios con cadenas \n \n"
               "Elige una de las siguientes opciones: \n"
               "1. Longitud \n"
               "2. Concatenacion \n"
               "3. Potencia \n"
               "4. Inverso \n"
               "5. Prefijos \n"
               "6. Sufijos \n"
               "7. Subcadenas\n"
               "8. Salir \n"
               "\n Opcion: ");
        scanf("%d", &opcionOperacion);
        system("cls");
        switch (opcionOperacion)
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
            break;
        }
        case 3:
        {
            printf("Ingrese Cadena A:\n");
            scanf("%s", A);
            for (i = strlen(A) - 1; i >= 0; i--)
            {
                a = A[i];
                if ((a == '1' || a == '0') != 1)
                {
                    printf("La cadena  A no es binaria\n");
                    system("pause");
                    return 0;
                }
            }
            int pot;
            printf("Escoja la potencia :");
            scanf("%d", &pot);
            potencia(A, pot);
        }
        break;
        // Opcion para Invertir cadena
        case 4:
        {
            printf("Ingrese Cadena A:\n");
            scanf("%s", A);
            for (i = strlen(A) - 1; i >= 0; i--)
            {
                a = A[i];
                if ((a == '1' || a == '0') != 1)
                {
                    printf("La cadena  A no es binaria\n");
                    system("pause");
                    return 0;
                }
            }
            inverso(A);
        }
        break;
        case 5:
        {
            char frase1[200];
            char frase2[200];
            printf("Ingresa la primer cadena \n");
            fflush(stdin);
            scanf("%[^\n]", frase1);
            char *f1;
            f1 = frase1;
            while (*f1 != '\0')
            {
                if (*f1 == '0' || *f1 == '1')
                {
                    f1++;
                }
                else
                {
                    printf("La cadena no es binaria");
                    return 0;
                }
            }
            printf("La frase introducida fue: %s\n", frase1);
            fflush(stdin);
            printf("Ingresa la segunda cadena \n");
            fflush(stdin);
            scanf("%[^\n]", frase2);
            char *f2;
            f2 = frase2;
            while (*f2 != '\0')
            {

                if (*f2 == '0' || *f2 == '1')
                {
                    f2++;
                }
                else
                {
                    printf("La cadena no es binaria");
                    return 0;
                }
            }
            printf("La frase introducida fue: %s\n", frase2);
            f1 = frase1;
            f2 = frase2;
            int prefijo = 0;
            if (strcmp(frase1, frase2) == 0)
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
                strncpy(extraida, frase1 + inicio, prefijo);
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
        printf("\n\nDeseas realizar otra operacion? (1/0): ");
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