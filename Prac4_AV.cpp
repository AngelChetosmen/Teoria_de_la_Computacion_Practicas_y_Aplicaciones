#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Declaración de variables
string cadenauno = "", cadenados = "", cadenaunoA = "", cadenadosA = "", auxiliar = "", espacio = " ";
int numero;
int i, r;

void compuno()
{
    replace(cadenauno.begin(), cadenauno.end(), '0', '2');
    replace(cadenauno.begin(), cadenauno.end(), '1', '0');
    replace(cadenauno.begin(), cadenauno.end(), '2', '1');
}

void compdos()
{
    replace(cadenados.begin(), cadenados.end(), '0', '2');
    replace(cadenados.begin(), cadenados.end(), '1', '0');
    replace(cadenados.begin(), cadenados.end(), '2', '1');
}

void Calc()
{
    cout << "La longitud de la cadena 1 (" << cadenauno << ") es: " << cadenauno.length() << endl;
    cout << "La longitud de la cadena 2 (" << cadenados << ") es: " << cadenados.length() << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    if (cadenados.length() == 0)
    {
        cout << "Su cadena 2 aún no existe :p" << endl;
    }
    else
    {
        compdos();
        cout << "Su nueva cadena 2 es: " << cadenados << endl;
    }
    cadenadosA = cadenados;
    compdos();
    cout << "El inverso de la cadena 2 es: " << cadenados << endl;
    // cadenadosA es la cadenados inicial;
    // cadenados es ahora su inversa;
    if (cadenados.length() == 0)
    {
        cout << "Su segunda cadena no es un palindromo porque no existe :p" << endl;
    }
    else
    {
        cadenadosA = cadenados;                        // El valor de la cadena auxiliar es igual al de la original
        reverse(cadenadosA.begin(), cadenadosA.end()); // La cadena auxiliar se invierte
        if (cadenauno == cadenadosA)                   // Para el caso 2 (de 4) se compara con la cadena 1
        {
            cout << "Su segunda cadena (" << cadenados << ") SI es un palindromo con la cadena 1, dado que es su inverso :) " << endl;
        }
        else
        {
            cout << "Su segunda cadena (" << cadenados << ") NO es un palindromo con la cadena 1, dado que no es su inverso :(" << endl;
        }
    }
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}

// Devuelve true si la cadena auxiliar si está dentro de la cadenauno
int subcanu(string auxiliar, string cadenauno)
{
    int M = auxiliar.length();
    int N = cadenauno.length();

    for (int i = 0; i <= N - M; i++)
    { // Un loop para ver los caracteres uno por uno
        int j;

        for (j = 0; j < M; j++) // Para el indice actual i busca si la cadena coincide
            if (cadenauno[i + j] != auxiliar[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}

// Devuelve true si la cadena auxiliar si está dentro de la cadenados
int subcand(string auxiliar, string cadenados)
{
    int M = auxiliar.length();
    int N = cadenados.length();

    for (int i = 0; i <= N - M; i++)
    { // Un loop para ver los caracteres uno por uno
        int j;

        for (j = 0; j < M; j++) // Para el indice actual i busca si la cadena coincide
            if (cadenados[i + j] != auxiliar[j])
                break;

        if (j == M)
            return i;
    }
    return -1;
}

int main()
{
uinput_u:
    printf("Ingrese su primer cadena (conformada por 1s, 0s y/o espacios)\n");
    getline(cin, cadenauno);
    cin.sync();
    for (i = 0; i < cadenauno.length(); i++)
    {
        if (!(cadenauno[i] == '0' or cadenauno[i] == '1' or cadenauno[i] == ' '))
        {
            printf("Esa no es una cadena binaria!!\n\n");
            goto uinput_u;
        }
    }
uinput_d:
    printf("\nIngrese su segunda cadena (conformada por 1s, 0s y/o espacios)\n");
    getline(cin, cadenados);
    cin.sync();
    for (i = 0; i < cadenados.length(); i++)
    {
        if (!(cadenados[i] == '0' or cadenados[i] == '1' or cadenados[i] == ' '))
        {
            printf("Esa no es una cadena binaria!!\n\n");
            goto uinput_d;
        }
    }
    cout << endl;
inicio:
    if (cadenauno.length() == 0)
    {
        cout << "Cadena 1: No existe" << endl;
    }
    else
    {
        cout << "Cadena 1: " << cadenauno << endl;
    }
    if (cadenados.length() == 0)
    {
        cout << "Cadena 2: No existe" << endl;
    }
    else
    {
        cout << "Cadena 2: " << cadenados << endl;
    }
    do
    {
        printf("1. Con dos arreglos\n");
        printf("2.Salir\n\n");

        scanf("%d", &numero);
        cout << endl;

        switch (numero)
        {

        case 1:
            cout << "Cadena 1: " << cadenauno << endl;
            cout << "Cadena 2: " << cadenados << endl;
            if (cadenauno == cadenados)
            {
                cout << "Son iguales las cadenas :)" << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
            }
            else
            {
                cout << "Son diferentes las cadenas :(" << endl;
                cout << "¿Te gustaria reemplazar las cadenas? 1. Si y cambiarlas por otras nuevas 2. No y seguir el proceso con las mismas." << endl;
                scanf("%d", &r);
                cout << endl;
                switch (r)
                {
                case 1:
                {
                unouno:
                    cout << "Ingrese su nueva cadena 1: ";
                    cin.sync();
                    getline(cin, cadenauno);
                    for (int i = 0; i < cadenauno.length(); i++)
                    {
                        if (!(cadenauno[i] == '0' or cadenauno[i] == '1' or cadenauno[i] == ' '))
                        { // Se asegura de solo poder ingresar 1s, 0s y espacios.
                            printf("Esa no es una cadena binaria!!\n\n");
                            goto unouno;
                        }
                    }
                dosdos:
                    cout << "Ingrese su nueva cadena 2: ";
                    getline(cin, cadenados);
                    for (int i = 0; i < cadenados.length(); i++)
                    {
                        if (!(cadenados[i] == '0' or cadenados[i] == '1' or cadenados[i] == ' '))
                        { // Se asegura de solo poder ingresar 1s, 0s y espacios.
                            printf("Esa no es una cadena binaria!!\n\n");
                            goto dosdos;
                        }
                    }
                    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                    cout << endl
                         << "Sus nuevas cadenas son:" << endl;
                }
                break;
                case 2:
                {
                    Calc();
                }
                default:
                    break;
                }
                cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
                goto inicio;
            }
            Calc();
            goto inicio;
            break;
        case 2:
            return 0;
            break;
        }
    } while (!(numero >= 1 and numero <= 2)); // Se asegura de que el usuario solo pueda digitar números del 1 al 2.
    return 0;
}