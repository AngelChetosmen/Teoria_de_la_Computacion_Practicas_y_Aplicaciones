//Autores
//Espinoza Garcia Hilario Sebastian
//Gonzalez Rodriguez Carlos Daniel
//Ortiz Martinez Juan Carlos 
//Vega Reyes José Ángel
//Creacion: 04/12/2022 Version:3 Version Final
//Descripción: Este programa lee un archivo
//			   fuente y detecta parejas de
//			   los caracteres (), [] y {}.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define Max 260

void contador(int frecUno, int frecDos, int carUno, int carDos){
	if(frecUno==frecDos){
		printf("\nEl numero de pares de %c %c en el archivo es: %d \n",carUno,carDos,frecUno);
	}
	else if(frecUno>frecDos){
		printf("\nEl numero de pares de %c %c en el archivo es: %d \n",carUno,carDos,frecUno);
		int dif=frecUno-frecDos;
		printf("Y hay %i del caracter '%c' que no cierra(n)\n ",dif,carUno);
	}
	else if(frecUno<frecDos){
		printf("\nEl numero de pares de %c %c en el archivo es: %d \n",carUno,carDos,frecUno);
		int dif=frecDos-frecUno;
		printf("Y hay %i del caracter '%c' que no abre(n)\n ",dif,carDos);
	}
}

int main(){
	FILE * archivo;//Se crea el apuntador archivo de tipo FILE..
	char nombreArchivo[Max],caracter;//El nombreArchivo tendrá una longitud másxima de 260 caracteres.
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
	
	while(!feof(archivo)){
		printf("%c",caracter);
		caracter=getc(archivo);
		aparicion[caracter]++;
	}
	
	Seleccion:
	printf("\nPor seleccione una opcion:\n");
	printf("1.Comprobar parentesis()\n");
	printf("2.Comprobar corchetes[]\n");
	printf("3.Comprobar llaves{}\n");
	printf("4.Comprobar parentesis triangulares<>\n");
	printf("5.Elegir otro archivo\n");
	printf("6.Salir del programa\n\n");
	scanf("%d", &numero);
	
	if(numero==1){
		contador(aparicion[40], aparicion[41], 40, 41);
		goto Seleccion;
	}
	else if(numero==2){
		contador(aparicion[91], aparicion[93], 91, 93);
		goto Seleccion;
	}
	else if(numero==3){
		contador(aparicion[123],aparicion[125],123,125);
		goto Seleccion;
	}
	else if(numero==4){
		contador(aparicion[60], aparicion[62], 60, 62);
		goto Seleccion;
	}
	else if(numero==5){
		fclose(archivo);
		goto Inicio;
	}
	else if(numero==6){
		return 0;
	}
	else{
		printf("Elige una opcion valida!!\n\n");
		goto Seleccion;
	}			
}