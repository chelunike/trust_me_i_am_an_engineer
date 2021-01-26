#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>


int esPrimo(int n);

int main(int argc, char *argv[]) {
	int min, max;

	//min = strtol(argv[1], NULL, 10);
	//max = strtol(argv[2], NULL, 10);

	read(STDIN_FILENO, &min, sizeof(int));
	read(STDIN_FILENO, &max, sizeof(int));

	for (int i=min; i<=max; i++) {
		if (esPrimo(i)) {
			write(STDOUT_FILENO, &i, sizeof(int));
		}
	}
}

int esPrimo(int n) {
	int bandera = 1;
	for (int i=2; i<sqrt(n); i++) {
		if (n % i == 0) {
			bandera = 0;
		}
	}
	return bandera;
}
