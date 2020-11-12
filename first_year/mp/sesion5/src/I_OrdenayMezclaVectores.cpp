#include <iostream>
using namespace std;

#include "FuncionesEj9.h"
#include "GeneradorAleatorioEnteros.h"

using namespace std;

const int TOPE = 100;

int main() {
	// Definicion de Variables
	int v1[TOPE], v2[TOPE], res[TOPE*2];
	int tam_v1, tam_v2; // 0 <= tam_v1, tam_v2 < TOPE
	int tam_res;
	int min, max;

	// Entrada de datos
	do{
		cout << "Tamaño Vector 1: ";
		cin >> tam_v1;
	} while( tam_v1 <= 0 || tam_v1 > TOPE );

	do{
		cout << "Tamaño Vector 2: ";
		cin >> tam_v2;
	} while( tam_v2 <= 0 || tam_v2 > TOPE );

	do{
		cout << "Intruzca minimo: ";
		cin >> min;
		cout << "Intruzca el maximo: ";
		cin >> max;
	} while( max < min );

	// Calculamos el tamñano del vector res
	tam_res = tam_v1 + tam_v2;

	// Rellenamos los vectores
	cout << "-- Rellenando vectores de forma aleatoria --" << endl;
	RellenaVectorAleatorio(v1, min, max, tam_v1);
	RellenaVectorAleatorio(v2, min, max, tam_v2);
	
	// Ordenamos los vectores
	cout << "-- Ordenando los vectores --" << endl;
	OrdenaSeleccion(v1, 0, tam_v1);
	OrdenaInsercion(v2, 0, tam_v2);

	// Mostramos los vectores
	cout << "vector 1: " << endl;
	PintaVectorEntero(v1, tam_v1);
	cout << "vector 2: " << endl;
	PintaVectorEntero(v2, tam_v2);

	// Ordenamos los vectores cada uno con un metodo distinto
	cout << "-- Mezclamos los vectores --" << endl;
	MezclaVectores(v1, v2 ,res, tam_v1, tam_v2);

	// Mostramos el vector mezclado
	cout << "Vector mezclado: " << endl;
	PintaVectorEntero(res, tam_res);		

	return 0;
}


