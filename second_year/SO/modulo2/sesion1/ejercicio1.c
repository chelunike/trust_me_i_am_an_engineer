/*
tarea1.c
Trabajo con llamadas al sistema del Sistema de Archivos ''POSIX 2.10 compliant''
Probad tras la ejecución del programa: $>cat archivo y $> od -c archivo
*/

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>

char buf1[]="abcdefghij";
char buf2[]="ABCDEFGHIJ";

int main(int argc, char *argv[]) {

	int fd;
	
	// Comprueba al abrir el archivo si hay errores
	if( (fd=open("archivo",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR))<0) {
		printf("\nError %d en open",errno);
		perror("\nError en open");
		exit(-1);
	}


	// Escribe en el archivo el array buff1
	// Escribe 10 y espera que sean 10 la respuesta
	// Puesto que el metodo write devuelve el num de escritos
	if(write(fd,buf1,10) != 10) {
		perror("\nError en primer write");
		exit(-1);
	}

	// Cambia la posicion del "cursor" a la posicion 40
	// al mover el cursor deja un espacio de 30 vacio con \0
	if(lseek(fd,40,SEEK_SET) < 0) {
		perror("\nError en lseek");
		exit(-1);
	}


	// Escribe el contenido de buf2 en el archivo
	if(write(fd,buf2,10) != 10) {
		perror("\nError en segundo write");
		exit(-1);
	}

	close(fd);
	return 0;
}

