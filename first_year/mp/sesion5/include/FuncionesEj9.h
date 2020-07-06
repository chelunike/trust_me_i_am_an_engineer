#include <iostream>

#include "GeneradorAleatorioEnteros.h"

using namespace std;

#ifndef FUNCIONES_EJ9
#define FUNCIONES_EJ9

void OrdenaSeleccion (int *v, int pos_inic, int pos_fin);
void OrdenaInsercion (int *v, int pos_inic, int pos_fin);
void OrdenaIntercambio (int *v, int pos_inic, int pos_fin);
void RellenaVectorAleatorio(int* pv, int min, int max, int fin);
void PintaVectorEntero(int* pv, int fin);
void MezclaVectores(int* v1, int* v2, int* res, int tam_v1, int tam_v2);

#endif