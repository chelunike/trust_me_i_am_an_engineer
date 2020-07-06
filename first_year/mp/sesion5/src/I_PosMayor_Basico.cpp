#include <iostream>

#include "FuncionesEj7.h"
#include "GeneradorAleatorioEnteros.h"

using namespace std;

const int TOPE = 100;

int main() {
	// Definicion de Variables
	int vector[TOPE];
	int total_vector;
	int min, max;
	int izq, dcha;

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
		cin >> izq;
		cout << "Intruzca el valor derecho: ";
		cin >> dcha;
	} while( dcha < izq );


	// Rellenamos el vector
	RellenaVectorAleatorio(vector, min, max, total_vector);
	
	// Mostramos el vector
	cout << "Nuestro Vector Generado: " << endl;
	PintaVectorEntero(vector, total_vector);

	// Sacamos el maximo dentro dentro del intervalo
	int* p_resultado;
	p_resultado = PosMayor(vector, izq, dcha);

	cout << "El numero mayor en el intervalo es: " << *p_resultado << endl;

	return 0;
}


