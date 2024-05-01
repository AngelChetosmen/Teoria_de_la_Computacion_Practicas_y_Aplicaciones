//Autor: Ortiz Martinez Juan Carlos
//Descripción: Este programa recibe un par de numeros
//			   binarios al inicio y permite que el
//			   usuario haga distintas operaciones
//			   con este.
//Fecha de creación: 01 de Noviembre de 2022.
//Versión 3

#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//Declaración de variables
string cadenauno="", cadenados="", cadenaunoA="", cadenadosA="", auxiliar="", espacio=" ";
int numero;
int i;

void compuno(){
	replace(cadenauno.begin(),cadenauno.end(),'0','2');
	replace(cadenauno.begin(),cadenauno.end(),'1','0');
	replace(cadenauno.begin(),cadenauno.end(),'2','1');
	
}

void compdos(){
	replace(cadenados.begin(),cadenados.end(),'0','2');
	replace(cadenados.begin(),cadenados.end(),'1','0');
	replace(cadenados.begin(),cadenados.end(),'2','1');
	
}

//Devuelve true si la cadena auxiliar si está dentro de la cadenauno
int subcanu(string auxiliar, string cadenauno)
{
	int M = auxiliar.length();
	int N = cadenauno.length();

	for (int i = 0; i <= N - M; i++) {//Un loop para ver los caracteres uno por uno
		int j;

		for (j = 0; j < M; j++)//Para el indice actual i busca si la cadena coincide
			if (cadenauno[i + j] != auxiliar[j])
				break;

		if (j == M)
			return i;
	}

	return -1;
}

//Devuelve true si la cadena auxiliar si está dentro de la cadenados
int subcand(string auxiliar, string cadenados)
{
	int M = auxiliar.length();
	int N = cadenados.length();

	for (int i = 0; i <= N - M; i++) {//Un loop para ver los caracteres uno por uno
		int j;

		for (j = 0; j < M; j++)//Para el indice actual i busca si la cadena coincide
			if (cadenados[i + j] != auxiliar[j])
				break;

		if (j == M)
			return i;
	}
	return -1;
}



int main(){
	uinput_u:
	printf("Ingrese su primer cadena (conformada por 1s, 0s y/o espacios)\n");
	getline(cin, cadenauno);
	cin.sync();
	for(i=0; i<cadenauno.length(); i++){
		if (!(cadenauno[i]=='0' or cadenauno[i]=='1' or cadenauno[i]==' ')){
			printf("Esa no es una cadena binaria!!\n\n");
			goto uinput_u;
		}
	}
	uinput_d:
	printf("\nIngrese su segunda cadena (conformada por 1s, 0s y/o espacios)\n");
	getline(cin, cadenados);
	cin.sync();
	for(i=0; i<cadenados.length(); i++){
		if (!(cadenados[i]=='0' or cadenados[i]=='1' or cadenados[i]==' ')){
			printf("Esa no es una cadena binaria!!\n\n");
			goto uinput_d;
		}
	}
	cout << endl;
	inicio:
		if(cadenauno.length()==0){
			cout << "Cadena 1: No existe" << endl;
		}else{
			cout << "Cadena 1: " << cadenauno << endl;
		}
		if(cadenados.length()==0){
			cout << "Cadena 2: No existe" << endl;
		}else{
			cout << "Cadena 2: " << cadenados << endl;
		}
	do{
		printf("\n1.Calcular longitud de las cadenas\n");
		printf("2.Comprobar si las cadenas son iguales\n");
		printf("3.Comprobar si las cadenas son palindromos\n");
		printf("4.Reemplazo de cadenas\n");
		printf("5.Eliminar espacios en blanco\n");
		printf("6.Complemento a 1\n");
		printf("7.Busqueda de una cadena dentro de otra\n");						
		printf("8.Salir\n\n");
	
		scanf("%d", &numero);
		cout<< endl;
			
		switch(numero){
			
		    case 1:
		    	cout << "La longitud de la cadena 1 (" << cadenauno << ") es: " << cadenauno.length() << endl;
		    	cout << "La longitud de la cadena 2 (" << cadenados << ") es: " << cadenados.length() << endl;
		    	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		    	goto inicio;
		    break;
		    
		    case 2:
		    	uno:
				cout << "Cadena 1: " << cadenauno << endl;
				cout << "Cadena 2: " << cadenados << endl;
				if(cadenauno==cadenados){
					cout << "Son iguales :)" << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					goto inicio;
				}else{
					cout << "Son diferentes :(" << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					goto inicio;
				}
			
			case 3:
				if(cadenauno.length()==0){
					cout << "Su primer cadena no es un palindromo porque no existe :p" << endl;
				}	else{
						cadenaunoA = cadenauno;//El valor de la cadena auxiliar es igual al de la original
						reverse(cadenaunoA.begin(),cadenaunoA.end());//La cadena auxiliar se invierte
						if(cadenauno==cadenaunoA){			
						cout << "Su primer cadena (" << cadenauno << ") SI es un palindromo :)" << endl;
					}	else{
							cout << "Su primer cadena (" << cadenauno << ") NO es un palindromo :(" << endl;
						}
					}	
					
				if(cadenados.length()==0){
				cout << "Su segunda cadena no es un palindromo porque no existe :p" << endl;
				}	else{
						cadenadosA = cadenados;//El valor de la cadena auxiliar es igual al de la original
						reverse(cadenadosA.begin(),cadenadosA.end());//La cadena auxiliar se invierte
						if(cadenados==cadenadosA){			
							cout << "Su segunda cadena (" << cadenados << ") SI es un palindromo :)" << endl;
						}	else{
								cout << "Su segunda cadena (" << cadenados << ") NO es un palindromo :(" << endl;
							}
					}
							
					cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
					goto inicio;
				break;
			
			case 4:
				cuatro:
				cout << "Ingrese su nueva cadena 1: ";
				cin.sync();
				getline(cin, cadenauno);
				for(int i=0; i<cadenauno.length(); i++){
					if (!(cadenauno[i]=='0' or cadenauno[i]=='1' or cadenauno[i]==' ')){ //Se asegura de solo poder ingresar 1s, 0s y espacios.
						printf("Esa no es una cadena binaria!!\n\n");
						goto cuatro;
					}
				}
				cuatrodos:
				cout << "Ingrese su nueva cadena 2: ";
				getline(cin, cadenados);
				for(int i=0; i<cadenados.length(); i++){
					if (!(cadenados[i]=='0' or cadenados[i]=='1' or cadenados[i]==' ')){ //Se asegura de solo poder ingresar 1s, 0s y espacios.
						printf("Esa no es una cadena binaria!!\n\n");
						goto cuatrodos;
					}
				}
		    	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << endl << "Sus nuevas cadenas son:" << endl;
				goto inicio;
				
			break;
			
			case 5:
				cinco:
				cout << "De que cadena desea eliminar los espacios en blanco?" << endl;
				printf("\n1.De la cadena uno\n");
				printf("2.De la cadena dos\n");
				scanf("%d", &numero);
				if(numero==1){
					if(cadenauno.length()==0){
						cout << "La cadena 1 no existe, no se elimino nada" << endl;
					}else{
						int res = subcanu(espacio, cadenauno);
						if (res == -1){//Cuando la condición es falsa no hay espacios
							cout << "La cadena 1 no tiene espacios, no se elimino nada" << endl;
						}	else{
								cadenauno.erase(remove(cadenauno.begin(),cadenauno.end(),' '), cadenauno.end());
							}
					}
				}
				else
					if(numero==2){
						if(cadenados.length()==0){
							cout << "La cadena 2 no existe, no se elimino nada" << endl;
						}else{
							int res = subcand(espacio, cadenados);
							if (res == -1){//Cuando la condición es falsa no hay espacios
								cout << "La cadena 2 no tiene espacios, no se elimino nada" << endl;
							}	else{
									cadenados.erase(remove(cadenados.begin(),cadenados.end(),' '), cadenados.end());
								}
						}
					}	else{
							printf("Elija una opcion valida!!\n\n");
							fflush(stdin);
							goto cinco;
						}
		    	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				goto inicio;
			break;
			
			case 6:		
  				seis:
				cout << "De que cadena desea obtener su complemento?" << endl;
				printf("\n1.De la cadena uno\n");
				printf("2.De la cadena dos\n");
				printf("3.De ambas\n\n");
				scanf("%d", &numero);
				cout << endl;
				if(numero==1){
					if(cadenauno.length()==0){
						cout << "Su cadena 1 aun no existe :p" << endl;
					}else{
						compuno();
		  				cout << "Su nueva cadena 1 es: " << cadenauno << endl;
				     }
				}
				else
					if(numero==2){
						if(cadenados.length()==0){
							cout << "Su cadena 2 aún no existe :p" << endl;
						}else{
							compdos();
			  				cout << "Su nueva cadena 2 es: " << cadenados << endl;
							 }
						}
					else
						if(numero==3){
							if(cadenauno.length()==0){
								if(cadenados.length()==0){
									cout << "Su cadena 1 aun no existe :p" << endl;
									cout << "Su cadena 2 tampoco existe xD" << endl;
								}else{
									cout << "Su cadena 1 aun no existe :p" << endl;
									compdos();
									cout << "Su nueva cadena 2 es: " << cadenados << endl;		
								}							
							}else{
								if(cadenados.length()==0){
									compuno();
					  				cout << "Su nueva cadena 1 es: " << cadenauno << endl;
									cout << "Su cadena 2 aun no existe :p" << endl;
								}else{
									compuno();
					  				cout << "Su nueva cadena 1 es: " << cadenauno << endl;
									compdos();
									cout << "Su nueva cadena 2 es: " << cadenados << endl;		
								}		
							}
						}else{
								printf("Elija una opcion valida!!\n\n");
								fflush(stdin);
								goto cinco;
						 }
		    	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				goto inicio;
			break;
			
			case 7:{
				siete:
				cout << "Ingrese una cadena nueva para buscarla dentro de las cadenas 1 y 2" << endl; 
				cin.ignore();
				getline(cin, auxiliar);
				cin.sync();
				for(int i=0; i<auxiliar.length(); i++){
					if (!(auxiliar[i]=='0' or auxiliar[i]=='1' or auxiliar[i]==' ')){ //Se asegura de solo poder ingresar 1s, 0s y espacios.
						printf("Esa no es una cadena binaria!!\n\n");
						goto siete;
					}
				}
				
				if(cadenauno.length()==0){
					cout << "No se encuentra en la cadena 1 porque esta no existe" << endl;
				}else{
					int res = subcanu(auxiliar, cadenauno);
					if (res == -1){
						cout << "No se encuentra en la cadena 1" << endl;
					}	else{
							cout << "Si se encuentra en la cadena 1" << endl;
						}
				}
				
				if(cadenados.length()==0){
					cout << "No se encuentra en la cadena 2 porque esta no existe" << endl;
				}else{
					int res = subcand(auxiliar, cadenados);
					if (res == -1){
						cout << "No se encuentra en la cadena 2" << endl;
					}	else{
							cout << "Si se encuentra en la cadena 2" << endl;
						}
				}
			        cout << endl << endl;
			
				goto inicio;	
			break;
			}
			
			case 8:
				return 0;
			break;
		}	
	}while(!(numero>=1 and numero<=8)); //Se asegura de que el usuario solo pueda digitar números del 1 al 7.
	return 0;
}