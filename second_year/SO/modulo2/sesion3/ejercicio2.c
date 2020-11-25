//ejercicio2 | tarea4.c
//Trabajo con llamadas al sistema del Subsistema de Procesos "POSIX 2.10 compliant"
//Prueba el programa tal y como está. Después, elimina los comentarios (1) y pruebalo de nuevo.

/*

¿Qué hace el siguiente programa? Intenta entender lo que ocurre con las variables
y sobre todo con los mensajes por pantalla cuando el núcleo tiene activado/desactivado el
mecanismo de buffering.

*/

#include<sys/types.h>	//Primitive system data types for abstraction of implementation-dependent data types.
						//POSIX Standard: 2.6 Primitive System Data Types <sys/types.h>
#include<unistd.h>		//POSIX Standard: 2.10 Symbolic Constants         <unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>

int global=6;
char buf[]="cualquier mensaje de salida\n";

int main(int argc, char *argv[]) {
	int var;
	pid_t pid;

	var=88;
	// Con el write los datos se escriben dirrectamente sin buffer de por medio
	if(write(STDOUT_FILENO,buf,sizeof(buf)+1) != sizeof(buf)+1) {
		perror("\nError en write");
		exit(EXIT_FAILURE);
	}
	
	// Inhabilita el buffering de la biblioteca estandar (printf) 
	if(setvbuf(stdout,NULL,_IONBF,0)) {
		perror("\nError en setvbuf");
	}

	printf("\nMensaje previo a la ejecución de fork");
	if((pid=fork()) < 0) {
		perror("\nError en el fork");
		exit(EXIT_FAILURE);
	} else if(pid == 0) {  
		//proceso hijo ejecutando el programa
		global++;
		var++;
	} else  //proceso padre ejecutando el programa
		sleep(1);	
	
	printf("\npid= %d, global= %d, var= %d\n", getpid(),global,var);
	exit(EXIT_SUCCESS);
}

/*

	Salida con buffer:
	cualquier mensaje de salida

	Mensaje previo a la ejecución de fork
	pid= 65984, global= 7, var= 89
	Mensaje previo a la ejecución de fork
	pid= 65983, global= 6, var= 88
	
	Salidad sin buffer:
	cualquier mensaje de salida

	Mensaje previo a la ejecución de fork
	pid= 66141, global= 7, var= 89

	pid= 66140, global= 6, var= 88


*/


