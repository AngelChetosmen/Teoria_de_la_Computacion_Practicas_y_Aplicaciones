#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Declaración de variables
string cadenauno = "", cadenados = "", cadenaunoA = "", cadenadosA = "", auxiliar = "", espacio = " ";
int numero;
int i, r, n1, n2;
// Declaración de la estructura pila
struct Nodo
{
    int dat;
    Nodo *siguiente;
};
void AgregarPila(Nodo *&pila, int n)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dat = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout << "Elemento" << n << " Agregando a pila correctamente" << endl;
}
int main()
{
    Nodo *pila = NULL;

uinput_u:
    printf("Ingrese su expresion aritmética\n");
    getline(cin, cadenauno);
    cin.sync();
    /* Verificar lo que menciona en la prac 5
    for (i = 0; i < cadenauno.length(); i++)
    {
        if (!(cadenauno[i] == '0' or cadenauno[i] == '1' or cadenauno[i] == ' '))
        {
            printf("Esa no es una cadena binaria!!\n\n");
            goto uinput_u;
        }
    }
    */
    cout << endl;
inicio:
    if (cadenauno.length() == 0)
    {
        cout << "La expresión no existe" << endl;
    }
    else
    {
        cout << "Expresión aritmetica: " << cadenauno << endl;
    }
    do
    {
        printf("Elige cual de las notaciones quieres obtener\n");
        printf("1. Notación Prefija\n");
        printf("2. Notación Posfija\n");
        printf("3. Notación Infija\n");
        scanf("%d", &numero);
        cout << endl;
        switch (numero)
        {
        case 1:
            cout << "La expresión que insertó es: " << cadenauno << endl;
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            exit(0);
        }
    } while (!(numero >= 1 and numero <= 3)); // Se asegura de que el usuario solo pueda digitar números del 1 al 3.
    return 0;
}