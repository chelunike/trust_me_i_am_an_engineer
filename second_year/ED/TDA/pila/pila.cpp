
#include <cstring>
#include <cassert>

#include "pila.h"


Pila::Pila() {
	primera = 0;	
}

Pila::Pila(const Pila & p) {
	copiar(p);
}

Pila::~Pila() {
	liberar();
}

Pila & Pila::operator=(const Pila &p) {
	if (this != &p) {
		liberar();
		copiar(p);
	}
	return *this;
}

bool Pila::vacia() const {
	return (primera == 0);
}

void Pila::poner(const Tbase &c) {
	CeldaPila* aux = new CeldaPila;
	aux->elemento = c;
	aux->sig = primera;
	primera = aux;
}

void Pila::quitar() {
	CeldaPila* aux = primera;
	if (primera->sig != 0)
		primera = primera->sig;
	else
		primera = 0;
	delete aux;
}

Tbase & Pila::tope() {
	return primera->elemento;
}

const Tbase & Pila::tope() const {
	return primera->elemento;
}

void Pila::copy(const Pila &p) {
	liberar();
	pila = Pila();
	
	while (!p.vacia()) {
		pila.poner(p.tope());
		p.quitar();
	}

	while(!pila.vacia()) {
		poner(pila.tope());
		p.poner(pila.tope());
		pila.quitar(());
	}

}

void Pila::liberar() {
	while(!vacia())
		quitar();
}


