
#include <cstring>
#include <cassert>

#include "pila.h"


//No se incluyen constructores, destructor ni operador de asignación
Pila::Pila(int tam) {
	datos = new Tbase[tam];
	nelem = 0;
}

Pila::Pila(const Pila & p) {
	liberar();
	datos = new Tbase[p.reservados];
	nelem = p.nelem;
	reservados = p.reservados;
	memcpy(datos, p.datos, sizeof(Tbase)*reservados);
}

Pila::~Pila() {
	liberar();
}

Pila & Pila::operator=(const Pila &p) {
	nelem = p.nelem;
	for (int i = 0; i < p.nelem; ++i) {
		datos[i] = p.datos[i];
	}
	return (*this);
}

bool Pila::vacia() const {
	return (nelem == 0);
}

void Pila::poner(const Tbase &c) {
	if (nelem==reservados)
		resize(2*reservados);
	datos[nelem++] = c;
}

void Pila::quitar() {
	assert(nelem > 0);
	nelem--;
	if (nelem<reservados/4)
		resize(reservados/4);
}

Tbase & Pila::tope() {
	assert(nelem > 0);
	return datos[nelem-1];
}

const Tbase & Pila::tope() const {
	assert(nelem > 0);
	return datos[nelem-1];
}

int Pila::length() {
    return nelem;
}

const int Pila::length() const {
    return nelem;
}

void Pila::resize(int n) {
	assert(n > nelem);
	Tbase* tmp = datos;
	datos = new Tbase[n];
	memcpy(datos, tmp, sizeof(Tbase)*n);
	delete(datos);
}

void Pila::copy(const Pila &p) {
	liberar();
	int tam = p.length();
	datos = new Tbase[tam];
	nelem = tam;
	reservados = tam;
	memcpy(datos, &p.tope()-tam, sizeof(Tbase)*tam);
}

void Pila::liberar() {
	delete(datos);
	nelem = 0;
	reservados = 0;
}

void Pila::reservar(int n) {
	resize(reservados+n);
}


