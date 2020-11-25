#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int regulares = 0;
int tam = 0;

void buscar(DIR *dir, char *pathname);

int main(int argc, char *argv[])
{
	DIR *dir;

	printf("\nLos i-nodos son:\n");

	if (argc == 2) {
		dir = opendir(argv[1]);
		buscar(dir, argv[1]);
	} else {
		dir = opendir(".");
		buscar(dir, ".");
	}

	printf("\nExisten %d archivos regulares con permiso x para grupo y otros\n", regulares);
	printf("El tamaño total ocupado por dichos archivos es %d bytes\n\n", tam);

	closedir(dir);
}

void buscar(DIR *dir, char *pathname)
{
	struct dirent *entrada;
	struct stat atributos;
	char ruta[512];
	DIR *subdir;


	while((entrada = readdir(dir)) != 0) {
		if (strcmp(entrada->d_name, ".") && strcmp(entrada->d_name, "..")) {
			sprintf(ruta, "%s/%s", pathname, entrada->d_name);
			lstat(ruta, &atributos);

			if (S_ISREG(atributos.st_mode) && (atributos.st_mode & S_IXGRP) && (atributos.st_mode & S_IXOTH)) {
				printf("%s %d\n", ruta, atributos.st_ino);
				regulares++;
				tam += atributos.st_size;
			} else if (S_ISDIR(atributos.st_mode)) {
				subdir = opendir(ruta);
				buscar(subdir, ruta);
				closedir(subdir);
			}
		}
	}
}