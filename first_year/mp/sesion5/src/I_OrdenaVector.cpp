#include <iostream>

#include "FuncionesEj8.h"
#include "GeneradorAleatorioEnteros.h"

using namespace std;

const int TOPE = 100;

int main() {
	// Definicion de Variables
	int v1[TOPE], v2[TOPE], v3[TOPE];
	int total_vector;
	int min, max;
	int pos_inic, pos_fin;

	// Entrada de datos
	do{
		cout << "Cantidad de numeros a generar: ";
		cin >> total_vector;
	} while( total_vector <= 0 || total_vector > TOPE );

	do{
		cout << "Intruzca minimo: ";
		cin >> min;
		cout << "Intruzca el maximo: ";
		cin >> max;
	} while( max < min );

	do{
		cout << "Intruzca el valor izquierdo: ";
		cin >> pos_inic;
		cout << "Intruzca el valor derecho: ";
		cin >> pos_fin;
	} while( pos_fin < pos_inic );


	// Rellenamos los vectores
	RellenaVectorAleatorio(v1, min, max, total_vector);
	RellenaVectorAleatorio(v2, min, max, total_vector);
	RellenaVectorAleatorio(v3, min, max, total_vector);
	
	// Mostramos los vectores
	cout << "vector 1: " << endl;
	PintaVectorEntero(v1, total_vector);
	cout << "vector 2: " << endl;
	PintaVectorEntero(v2, total_vector);
	cout << "vector 3: " << endl;
	PintaVectorEntero(v3, total_vector);

	// Ordenamos los vectores cada uno con un metodo distinto
	cout << "-- Ordenamos los vectores --" << endl;
	OrdenaSeleccion(v1, pos_inic, pos_fin);
	OrdenaInsercion(v2, pos_inic, pos_fin);
	OrdenaIntercambio(v3, pos_inic, pos_fin);

	// Volvemos a mostrar los vectores
	cout << "vector 1: " << endl;
	PintaVectorEntero(v1, total_vector);
	cout << "vector 2: " << endl;
	PintaVectorEntero(v2, total_vector);
	cout << "vector 3: " << endl;
	PintaVectorEntero(v3, total_vector);		

	return 0;
}


