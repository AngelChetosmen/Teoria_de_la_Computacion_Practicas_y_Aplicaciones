//Autores
//Espinoza Garcia Hilario Sebastian
//Gonzalez Rodriguez Carlos Daniel
//Ortiz Martinez Juan Carlos 
//Vega Reyes José Ángel
//Creacion: 12/12/2022 Version:3 Version Final
//Descripción: Realizar un programa en lenguaje C que dado un archivo
//fuente .C detecte los TOKENS correspondientes.
//Actividades:
//1. Programar en ANSI C, la detección de los siguientes tokens:
// Identificadores
// Operadores
// Signos de puntuación (puntuadores)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define Max 260

int repe;
char nombreArchivo[Max];

void busquedaglobal(string busqueda, int num){//Recibe 2 parametros
	repe=0;
	ifstream nameFileout;
	nameFileout.open(nombreArchivo);
	string line;
	while(getline(nameFileout,line)){
		size_t found = line.find(busqueda);
		if (found!=string::npos)
		repe++;
	}	
	if(num==1){
		cout << endl << "El numero de veces que un identificador tipo " << busqueda << "aparece en el archivo es: " << repe << endl;
	}
	else if(num==2){
		cout << endl << "El numero de veces que el operador " << busqueda << " aparece en el archivo es: " << repe << endl;
	}
	else if(num==3){
		cout << endl << "El numero de veces que el puntuador " << busqueda << " aparece en el archivo es: " << repe << endl;
	}
}

void contadorPar(int frecUno, int frecDos, int carUno, int carDos){
	if(frecUno==frecDos){
		printf("\nEl numero de pares de %c %c en el archivo es: %d \n",carUno,carDos,frecUno);
	}
	else if(frecUno>frecDos){
		printf("\nEl numero de pares de %c %c en el archivo es: %d \n",carUno,carDos,frecUno);
		int dif=frecUno-frecDos;
		printf("Y hay %i del caracter '%c' que no cierra(n) \n ",dif,carUno);
	}
	else if(frecUno<frecDos){
		printf("\nEl numero de pares de %c %c en el archivo es: %d \n",carUno,carDos,frecUno);
		int dif=frecDos-frecUno;
		printf("Y hay %i del caracter '%c' que no abre(n) \n ",dif,carDos);
	}
}

int main(){
	FILE * archivo;//Se crea el apuntador archivo de tipo FILE..
	char caracter;//El nombreArchivo tendrá una longitud másxima de 260 caracteres.
	int aparicion[256];
	int i=0,numero;
	
	printf("Hola! Este programa te permite buscar ciertos simbolos dentro del archivo de tu eleccion :).\n");
	
	Inicio:
	printf("Por favor introduce el nombre del archivo que desea abrir con su extension\n");
	printf("Ejemplo: archivo.txt\n");
	scanf("%s",&nombreArchivo);
	
	archivo=fopen(nombreArchivo,"r");
	
	for(i=0; i<256; i++){
		aparicion[i]=0;
	}
	
	if(!archivo){
		printf("\nEl archivo no existe o no tiene un formato aceptado\n\n");
		goto Inicio;
	}
	else
		printf("\nAbriendo...\n\n");
	
	char linea[250];
	
	while(!feof(archivo)){
		printf("%c",caracter);
		caracter=getc(archivo);
		aparicion[caracter]++;
	}
	
	principal:
	printf("\n\nPor seleccione una opcion:\n");
	printf("1.Detectar identificadores\n");
	printf("2.Detectar operadores\n");
	printf("3.Detectar puntuadores\n");
	printf("4.Elegir otro archivo\n");
	printf("5.Salir\n");
	scanf("%d", &numero);
	
	if(numero==1){
		busquedaglobal("char ",1);
		busquedaglobal("unsigned char ",1);
		busquedaglobal("string ",1);
		busquedaglobal("int ",1);
		busquedaglobal("short int ",1);
		busquedaglobal("unsigned short ",1);
		busquedaglobal("unsigned int ",1);
		busquedaglobal("long ",1);
		busquedaglobal("unsigned long long ",1);
		busquedaglobal("unsigned long ",1);
		busquedaglobal("float ",1);
		busquedaglobal("double ",1);
		busquedaglobal("long double ",1);
		busquedaglobal("bool ",1);		
	}
	
	else if(numero==2){
		busquedaglobal("+",2);
		busquedaglobal("++",2);
		busquedaglobal(".",2);
		busquedaglobal("!",2);
		busquedaglobal("!=",2);
		busquedaglobal("%",2);
		busquedaglobal("^",2);
		busquedaglobal("&",2);
		busquedaglobal("-",2);
		busquedaglobal("+",2);
		busquedaglobal("|",2);
		busquedaglobal("~",2);
		busquedaglobal("'",2);
		busquedaglobal("<",2);
		busquedaglobal(">",2);
		busquedaglobal("?",2);
		busquedaglobal("/",2);	
	}
	
	else if(numero==3){
		contadorPar(aparicion[40], aparicion[41], 40, 41);
		contadorPar(aparicion[91], aparicion[93], 91, 93);
		contadorPar(aparicion[123],aparicion[125],123,125);
		contadorPar(aparicion[60], aparicion[62], 60, 62);
		busquedaglobal(",",3);
		busquedaglobal(";",3);
		busquedaglobal(":",3);
		busquedaglobal("...",3);
		busquedaglobal("*",3);
		busquedaglobal("=",3);
		busquedaglobal("#",3);
	}
	else if(numero==4){
		fclose(archivo);
		goto Inicio;
	}
	else if(numero==5){
		fclose(archivo);
		return 0;
	}
	goto principal;
}
