// Ejercicio 2

#include <sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include <unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


int int main(int argc, char const *argv[]) {
	char* path, permisos;
	char pathname[512];
	DIR *dir;
	int permisosNuevos, permisosAntiguos;

	// Comprobamos los parametros
	if (argc < 3 || argc > 4) {
		printf("Numero de parametros invalido.\n");
		printf("Uso %s <pathname> <permisos> \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// Recojemos los datos
	path = argv[1];
	permisos = argv[2];

	dir = opendir(path);
	permisosAntiguos = strtol(permisos, NULL, 8);

	struct dirent* entrada;
	struct stat *atributos;
	while((entrada = readdir(dir)) != 0) {
		if (strcmp(entrada->d_name, ".") && strcmp(entrada->d_name, "..")) {
			sprintf(pathname, "%s/%s\n", path, entrada->d_name);
			lstat(pathname, &atributos);
			permisosAntiguos = atributos.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);

			if (chmod(pathname, permisosNuevos) == 0) {
				//printf("Nombre : <permisosAntiguos> <permisosNuevos> \n");
				printf("%s : %d %d\n", entrada->d_name, permisosAntiguos, permisosNuevos);
			} else {
				//printf("Nombre : <errno> <permisosAntiguos> \n");
				printf("%s : %d %d\n", entrada->d_name, errno, permisosAntiguos);

			}

		}
	}


	return 0;
}