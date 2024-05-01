#include <stdio.h>
#include <string.h>
void valido(char[], int);
void potl(char *, int, int);
char *pot(char[], int);
char *invertir(char[], int);
void prefijo(char[], int);
int main()
{

	char cadena1[50], cadena2[50], cadena[50], concat[100];
	int num, n;

	printf("Ingresa la primer cadena(max 50 caracteres y con caracteres 'a' y 'b')\n");
	scanf("%s", &cadena1);

	int longitud = strlen(cadena1);
	valido(cadena1, longitud);

	printf("Ingresa la segunda cadena(max 50 caracteres y con caracteres 'a' y 'b')\n");
	scanf("%s", &cadena2);

	int longitud2 = strlen(cadena2);
	valido(cadena2, longitud2);

	printf("Seleccione la opci�n a realizar\n 1.-Concatenacion de 2 cadenas\n 2.-Potencia de cadena\n 3.-Inverso de una cadena\n 4.-Prefijo y sufijo de una cadena\n 5.-Subcadenas\n");
	scanf("%d", &num);

	switch (num)
	{

	case 1:
		strcat(strcpy(concat, cadena1), cadena2);
		printf("la concatenacion de las cadenas es: %s\n", concat);
		break;

	case 2:
		printf("Ingresa la potencia\n");
		scanf("%d", &n);
		printf("la potencia %d de la cadena 1 es: %s\n", n, pot(cadena1, longitud));
		printf("la potencia %d de la cadena 2 es: %s\n", n, pot(cadena2, longitud2));
		break;

		potl(cadena1, longitud, n);

		break;

	case 3:
		printf("La inversa de la cadena 1 es: %s\n", invertir(cadena1, longitud));
		printf("La inversa de la cadena 2 es: %s\n", invertir(cadena2, longitud2));
		break;

	case 4:
		prefijo(cadena1, longitud);

		break;

	case 5:
		break;
	}

	return 0;
}

void valido(char cadena[], int longitud)
{
	int i = 0;
	while (i < longitud)
	{
		if (cadena[i] == 'a' || cadena[i] == 'b')
		{
			i++;
		}
		else
		{
			printf("Error cadena invalida\n");
			exit(0);
		}
	}
	printf("Cadena valida\n");
}

void potl(char cadena[], int longitud, int n)
{
	int i = 0;
	char *auxiliar;
	char *auxiliar2;
	auxiliar = cadena;

	printf("%s\n", auxiliar);
}

char *pot(char cadena[], int longitud)
{

	int i, n;
	for (i = 0; i < n; i++)
	{
		// printf("%d \t", n);
		// printf ("%d * %d = %d \n",n, n, i*n);
	}
	return cadena;
}

char *invertir(char cadena[], int longitud)
{
	char temporal;
	int izquierda, derecha = longitud - 1;
	for (izquierda = 0; izquierda < (longitud / 2); izquierda++, derecha--)
	{
		temporal = cadena[izquierda];
		cadena[izquierda] = cadena[derecha];
		cadena[derecha] = temporal;
	}
	return cadena;
}

void prefijo(char cadena[], int longitud)
{
	int i = 0;

	while (i < longitud)
	{
		printf("%c\n", cadena);
		i++;
	}
}