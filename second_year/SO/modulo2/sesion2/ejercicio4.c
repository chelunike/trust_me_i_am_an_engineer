/* Programa que recorre un sub-árbol con la función nftw */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ftw.h>


int count = 0;
int tam = 0;

int buscar(const char* path, const struct stat* stat, int flags, struct FTW* ftw) {
	//printf ("Path: %s Modo: %o \n",path, stat->st_mode);
	printf("%s\t%ld\n", path, stat->st_ino);
	if (S_ISREG(stat->st_mode) && (stat->st_mode & (S_IXGRP|S_IXOTH)) ) {
		count++;
		tam += stat->st_size;
	}
	return 0;
}

int main(int argc, char** argv) {

	// Comprobamos los parametros
	if (argc < 2 || argc > 2) {
		printf("Numero de parametros invalido.\n");
		printf("Uso %s <pathname> \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	printf("Los i-nodos son:\n");
	if (nftw(argv[1], buscar, 10, 0) != 0) {
		perror("Error en nftw");
		exit(EXIT_FAILURE);	
	}
	printf("Existen %d archivos regulares con permiso x para grupo y otros.\n", count);
	printf("El tamañano total ocupado por dichos archivos es %d bytes.\n", tam);
}


