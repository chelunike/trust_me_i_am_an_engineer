/*
tarea2.c
Trabajo con llamadas al sistema del Sistema de Archivos ''POSIX 2.10 compliant''

El programa acepta como argumento el nombre de un archivo (pathname), 
lo abre y lo lee en bloques de tamaño 80 Bytes, y crea un nuevo archivo 
de salida, salida.txt, en el que debe aparecer la siguiente información:

// Formato de: salida.txt 
Bloque 1
// Aquí van los primeros 80 Bytes del archivo pasado como argumento.
Bloque 2
// Aquí van los siguientes 80 Bytes del archivo pasado como argumento.

*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>


int main(int argc, char *argv[]) {
	
	int N_BLOQUES = 3;

	// Tamaño que vamos a leer
	int TAM_BLOQUE = 80;

	// Almacenamiento temporal para lo que vamos a leer
	char cabecera[] = "Bloque X\n";
	char buf1[TAM_BLOQUE];
	char buf2[TAM_BLOQUE];

	int fichero1, fichero2;

	// Controlo el num de parametros
	if (argc < 2 || argc > 3) {
		printf("\nError en el numero de argumentos esperando 1, recibidos: %d", (argc-1));
		exit(-1);
	}

	// Abrimos los archivos

	// Archivo de lectura 
	// open("path", int flags, mode_t mode  )
	// 		flags: (indica si va a ser lectura o escritura)
	// 		mode: mascara de permisos (ej: 750, pero se especifica  S_IRWXU)
	//      mode:  S_I + permisos (R , W, X) + relleno de quien es el permiso (USR , GRP, OTH)
	printf("\nAbriendo %s", argv[1]);
	if ( (fichero1=open(argv[1],O_RDONLY,S_IRUSR|S_IRUSR))<0) {
		printf("\nError %d en open",errno);
		perror("\nError en el primer open");
		exit(-1);
	}

	// Archivo de salida
	printf("\nAbriendo salida.txt");
	if ( (fichero2=open("salida.txt",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR))<0) {
		printf("\nError %d en open",errno);
		perror("\nError en el segundo open");
		exit(-1);
	}


	for (int i=1; i<=N_BLOQUES; ++i) {

		// Leemos de nuestro fichero
		// ssize_t read (int fd, void *buf, size_t count);
		// Devuelve n leidos o 0 si el offset(cursor) esta al final
		// OJO, que mueve el offset(cursor)
		printf("\nLeyendo los primeros bytes");
		if (read(fichero1, buf1, TAM_BLOQUE) <= 0) {
			perror("\nError en read");
			exit(-1);
		}

		// Escribimos en nuestro archivo
		printf("\nEscribiendo Bloque%i \n", i);
		printf(buf1);
		
		// Primero la cabecera
		cabecera[7] = i+'0';
		if (write(fichero2, cabecera, 10) != 10) {
			perror("\nError al escribir cabecera");
			exit(-1);
		}

		// Luego los datos
		if (write(fichero2, buf1, TAM_BLOQUE) != TAM_BLOQUE) {
			perror("\nError en el write");
			exit(-1);
		}	
	}


	// Cerramos los ficheros
	close(fichero1);
	close(fichero2);

	return 0;

}

