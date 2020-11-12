#include <iostream>
#include <iomanip>


using namespace std;


// Constantes
const int MAX_CARACTERES = 100; 
const int MAX_PALABRAS = 10;


int encuentra_palabras (char** palabras, char* cadena);


int main() {
	
	// Variables
	char cadena[MAX_CARACTERES];
	char* palabras[MAX_PALABRAS];


	cout << "Introduzca una cadena: ";
	cin.getline(cadena, MAX_CARACTERES);

	int num_palabras = encuentra_palabras_profe(palabras, cadena);

	cout << endl;
	cout << "La cadena tiene " << num_palabras << " palabras." << endl;
	cout << endl;

	cout << "Las palabras empiezan por: " << endl;
	for (int i=0; i<num_palabras; i++) {
		cout << setw(3) << i << ": " << *(las_palabras[i]) << endl; 
	}
	
	return (0);
}


int encuentra_palabras_profe(char** palabras, char* cadena) {
 	char *  p_cadena = cadena;		// recorre la cadena
	char ** p_palabras = palabras;	// recorre el vector de char *

	bool en_palabra = false;
	int num_palabras = 0;
 
	while (*p_cadena && num_palabras<MAX_PALABRAS) {

		if (!isspace(*p_cadena) && !en_palabra) { // Caso 1

				en_palabra = true;

				*p_palabras = p_cadena;
				p_palabras++;

				num_palabras++; // Otra palabra
		}
		else 

			if (isspace(*p_cadena) && en_palabra) { // Caso 2
		
				en_palabra = false; 

			}		

		p_cadena++; 
	}
 
	if (num_palabras==MAX_PALABRAS) {
		cerr << endl;
		cerr << "AVISO: Se ha llenado el array de palabras." << endl;
		cerr << endl;
	}

	int num_palabras_alternativo = p_palabras - palabras;
	if (num_palabras_alternativo != num_palabras) {
		cerr << "ERROR: inconsistencia en el numero de palabras" << endl;
		exit (1);
	}

	return (num_palabras);
}


