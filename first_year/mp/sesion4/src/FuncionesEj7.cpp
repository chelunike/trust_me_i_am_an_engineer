#include <iostream>

#include "GeneradorAleatorioEnteros.h"

using namespace std;


int* PosMayor(int *pv, int izda, int dcha) {
	int* mayor = pv+izda;

	for(int* i=(pv+izda); i <= (pv+dcha); i++) {
		if( *mayor < *i ) {
			mayor = i;
		}
	}
	return mayor;
}

void RellenaVectorAleatorio(int* pv, int min, int max, int fin) {
	GeneradorAleatorioEnteros generador(min, max);

	for(int i=0; i<fin; i++) {
		*(pv+i) = generador.Siguiente();
	}
}

void PintaVectorEntero(int* pv, int fin) {
	cout << "[ ";
	for(int* p=pv; p<(pv+fin); p++) {
		if (p == ( pv+fin -1))
			cout << *p;
		else
			cout << *p << ", ";
	}
	cout << " ]" << endl;
}
