#include <iostream>

#include "GeneradorAleatorioEnteros.h"

using namespace std;


void OrdenaSeleccion (int *v, int pos_inic, int pos_fin) {
	for(int i = pos_inic; i < pos_fin; ++i) {
		int min = i;
		for(int j = i+1; j < pos_fin; ++j)
			if(v[j] < v[min])
				min = j;
		// Swap Values
		int intercambio = v[min];
		v[min] = v[i];
		v[i] = intercambio;
	}
}


void OrdenaInsercion (int *v, int pos_inic, int pos_fin) {
	if(pos_fin > 1){
		for(int i = pos_inic + 1; i < pos_fin; ++i) {
			int j = i - 1;
			int key = v[i];
			while(j >= 0 && v[j] > key){
				v[j+1] = v[j];
				j--;
			}
			v[j+1] = key;
		}
	}
}


void OrdenaIntercambio (int *v, int pos_inic, int pos_fin) {
	for(int i=pos_inic; i<pos_fin; i++) {
		for(int j=i; j<pos_fin; j++) {
			if (v[i] > v[j]) {
				int intercambio = v[i];
				v[i] = v[j];
				v[j] = intercambio;
 			}
		}
	}
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

void MezclaVectores(int* v1, int* v2, int* res, int tam_v1, int tam_v2) {
	int* pv1 = v1;
	int* pv2 = v2;
	while ( pv1 < (v1+tam_v1) && pv2 < (v2+tam_v2)  ) {
		if (*pv1 < *pv2) {
			*res = *pv1;
			pv1++;
		} else {
			*res = *pv2;
			pv2++;
		}
		res++;
	}

	// Copiamos lo restante
	while ( pv1 < (v1+tam_v1) ) {
		*res = *pv1;
		pv1++;
		res++;
	}

	while ( pv2 < (v1+tam_v2) ) {
		*res = *pv2;
		pv2++;
		res++;
	}
}