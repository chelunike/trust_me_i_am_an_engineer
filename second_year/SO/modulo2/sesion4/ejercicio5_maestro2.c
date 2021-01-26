/*
Ejercicio 5

*/
/*
https://hastebin.com/uripolumuv.c
https://hastebin.com/gevicubose.c
*/

#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>


int main(int argc, char *argv[]) {
	int NESCLAVOS = 2;
	int min, max;
	int primo;

	int fdM[2], fdE[2];
	pid_t pid;

	if (argc != 3) {
		printf("Número de parametros invalido.\n");
		printf("Sintaxis: %s <min> <max>\n", argv[0]);
		exit(-1);
	}

	// Recogemos los valores 
	min = strtol(argv[1], NULL, 10);
	max = strtol(argv[2], NULL, 10);

	// Creamos el cauce del padre	
	pipe(fdM);

	// Creamos el pipe del esclavo
	pipe(fdE);

	int begin, end;
	int count = min;
	int size = (max -min) / NESCLAVOS;
	for (int i=0; i<NESCLAVOS; ++i) {
		// Calculamos rango de primos
		begin = count == min? count: ++count;
		end = (count + size)>max? max: count+size;
		count += size;
		
		// Cerramos los pipe innecesarios
		close(fdE[1]);


		if ((pid = fork()) < 0) {
			perror("\nError en fork"); // En caso error
			exit(EXIT_FAILURE);
		} else if(pid == 0) { // Proceso hijo (Esclavo)
			dup2(fdE[0], STDIN_FILENO);
			dup2(fdM[1], STDOUT_FILENO);
			
			if (execl("./esclavo", "esclavo", NULL) < 0) {
				perror("Error al ejecutar el comando.");
			}	
		} else { // Proceso padre (Maestro)
			// No necesitamos leer en el esclavo
			close(fdE[0]);

			// Mandamos los datos
			write(fdE[1], &begin, sizeof(int));
			write(fdE[1], &end, sizeof(int));
		}
	}


	//if (pid > 0) {
	// No necesitamos escribir
	close(fdM[1]);

	// Leemos los datos
	while(read(fdM[0], &primo, sizeof(int)) != 0) {
		printf("Primo leido: %d\n", primo);
	}
	//}

	printf("FIN\n");
	return EXIT_SUCCESS;
}


