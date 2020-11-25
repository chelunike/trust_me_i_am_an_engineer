// Ejercicio 1 :)
/*

Implementa un programa en C que tenga como argumento un número entero. Este
programa debe crear un proceso hijo que se encargará de comprobar si dicho número es un
número par o impar e informará al usuario con un mensaje que se enviará por la salida estándar.
A su vez, el proceso padre comprobará si dicho número es divisible por 4, e informará si lo es o
no usando igualmente la salida estándar.

*/

#include <stdio.h>   //printf
#include <stdlib.h>  //exit
#include <stdbool.h> //bool
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>


// Metodos a usar
bool esPar(const int n);
bool esDivisible(const int n, const int divisor);


int main(int argc, char const *argv[]) {
	int num;
	pid_t pid;

	// Comprobamos parametros
	if (argc < 2 || argc > 2) {
		printf("Número de parametros incorrecto\n");
		printf("Uso: %s <num>\n", argv[0]);
		exit(-1);
	}

	num = atoi(argv[1]);
	// Creamos proceso hijo y ejecutamos la accion
	if ((pid=fork()) < 0) {
		perror("Error al crear proceso hijo\n");
		exit(-1);
	} else if (pid == 0) { // Programa hijo
		printf("Proceso hijo: %d padre: %d.\n", getpid(), getppid());
		printf("El numero dado: %d es %s.\n", num, esPar(num)? "par":"impar");
	} else { // Programa padre
		printf("Proceso padre: %d.\n", getpid());
		printf("El numero dado: %d %s es divisible por 4.\n", num, 
			esDivisible(num, 4)? "SI":"NO");
	}
	return 0;
}

bool esPar(const int n) {
	return (n%2 == 0);
}

bool esDivisible(const int n, const int divisor) {
	return (n%divisor == 0);
}


