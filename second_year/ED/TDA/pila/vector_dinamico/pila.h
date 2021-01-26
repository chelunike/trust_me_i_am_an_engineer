#ifndef __PILA_H__
#define __PILA_H__

typedef char Tbase;
const int TAM = 10;

class Pila {
	
	private:
		Tbase *datos;
		int nelem;
		int reservados;

	public:
		
		Pila(int tam=TAM);
		
		Pila(const Pila & p);
		
		~Pila();
		
		Pila & operator=(const Pila &p);
		
		bool vacia() const;
		
		void poner(const Tbase &c);
		
		void quitar();
		
		Tbase & tope();

		int length();

        const int length() const;

		const Tbase & tope() const;


	private:
		void resize(int n);
		void copy(const Pila &p);
		void liberar();
		void reservar(int n);
};

#endif /* pila_h */