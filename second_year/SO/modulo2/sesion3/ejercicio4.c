// Ejercicio 4
/*

	Implementa un programa que lance cinco procesos hijo. Cada uno de ellos se
	identificará en la salida estándar, mostrando un mensaje del tipo 'Soy el hijo PID'. 
	
	El proceso padre simplemente tendrá que esperar la finalización de todos sus hijos 
	y cada vez que detecte la finalización de uno de sus hijos escribirá en la salida 
	estándar un mensaje del tipo:
		Acaba de finalizar mi hijo con <PID>
		Sólo me quedan <NUM_HIJOS> hijos vivos

*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include <unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[]) {
	int TAM = 5;
	pid_t procesos[TAM];

	printf(" -- INICIO EJECUTABLE -- \n");

	// Arrancamos todos los procesos
	for (int i=0; i < TAM; ++i) {
		if ((procesos[i] = fork()) < 0) {
			perror("Error al crear proceso hijo");
			exit(-1);
		} else if (procesos[i] == 0) {
			printf("Soy el hijo %d\n", getpid());
			sleep(i+1); // Metemos relleno
			exit(0);
		}
	}

	// Esperamos a que todos acaben
	int wstatus;
	for (int i=0; i < TAM; ++i) {
		waitpid(procesos[i], &wstatus, 0);
		printf("Acaba de finalizar mi hijo con  %d.\n", procesos[i]);
		printf("Sólo me quedan %d hijos vivos.\n", TAM-i-1);
	}

	printf(" -- FIN EJECUTABLE -- \n");
	return 0;
}


