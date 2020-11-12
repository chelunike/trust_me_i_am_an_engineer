#include <cassert>
#include "pila.h"


//No se incluyen constructores, destructor ni operador de asignación
Pila::Pila() {
	datos = new Tbase[TAM];
	nelem = 0;
}


Pila::~Pila() {
	del(datos);
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
	assert(nelem < TAM);
	datos[nelem++] = c;
}

void Pila::quitar() {
	assert(nelem > 0);
	nelem--;
}

Tbase & Pila::tope() {
	assert(nelem > 0);
	return datos[nelem-1];
}

const Tbase & Pila::tope() const {
	assert(nelem > 0);
	return tope();
}

void Pila::copy(const Pila &p) {
	
}

