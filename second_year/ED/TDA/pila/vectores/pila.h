#ifndef __PILA_H__
#define __PILA_H__

typedef char Tbase;
const int TAM = 500;

class Pila {
	
	private:
		Tbase datos[TAM];
		int nelem;

	public:
		
		Pila();
		
		Pila(const Pila & p);
		
		~Pila() = default;
		
		Pila & operator=(const Pila &p);
		
		bool vacia() const;
		
		void poner(const Tbase & c);
		
		void quitar();
		
		Tbase & tope();
		
		const Tbase & tope() const;

		private:
			void copiar(const Pila &p);
};

#endif /* pila_h */