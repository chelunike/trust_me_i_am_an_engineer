// ejercicio7.c
/*

Escribe un programa que acepte como argumentos el nombre de un programa, sus
argumentos si los tiene, y opcionalmente la cadena “bg”. Nuesto programa deberá ejecutar el
programa pasado como primer argumento en foreground si no se especifica la cadena “bg” y en
background en caso contrario. Si el programa tiene argumentos hay que ejecutarlo con éstos.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char const *argv[]) {
	bool bg = false;
	char *argumentos;

	// Comprobamos parametros
	if (argc < 2) {
		printf("Número de parametros incorrecto\n");
		printf("Uso: %s <programa> [argumentos] [bg]\n", argv[0]);
		exit(-1);
	}

	// Recogemos la opcion bg y los argumentos
	bg = strcmp("bg", argv[argc-1]);
	if (bg) {

	} else {

	}
	




	return 0;
}


