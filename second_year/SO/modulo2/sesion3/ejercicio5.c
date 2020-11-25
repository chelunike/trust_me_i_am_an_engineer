// Ejercicio 5
/*

	Implementa una modificación sobre el anterior programa en la que el proceso padre espera 
	primero a los hijos creados en orden impar (1o,3o,5o) y después a los hijos pares (2o y 4o).	

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
	for (int i=0; i < TAM; i++) {
		if ((procesos[i] = fork()) < 0) {
			perror("Error al crear proceso hijo");
			exit(-1);
		} else if (procesos[i] == 0) {
			printf("Soy el hijo %d\n", getpid());
			sleep(i+1); // Metemos relleno
			exit(0);
		}
	}

	// Esperamos primero los impares
	int wstatus, contador = TAM;
	for (int i=1; i < TAM; i+=2) {
		waitpid(procesos[i], &wstatus, 0);
		printf("Acaba de finalizar mi hijo con  %d.\n", procesos[i]);
		printf("Sólo me quedan %d hijos vivos.\n", --contador);
	}

	// Esperamos a los pares
	for (int i=0; i < TAM; i+=2) {
		waitpid(procesos[i], &wstatus, 0);
		printf("Acaba de finalizar mi hijo con  %d.\n", procesos[i]);
		printf("Sólo me quedan %d hijos vivos.\n", --contador);
	}

	printf(" -- FIN EJECUTABLE -- \n");
	return 0;
}


