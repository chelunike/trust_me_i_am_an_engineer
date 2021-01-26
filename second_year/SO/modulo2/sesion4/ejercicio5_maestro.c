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

	int fdM[2], fdE[NESCLAVOS][2];
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

	int begin, end;
	int count = min;
	int size = (max -min) / NESCLAVOS;
	for (int i=0; i<NESCLAVOS; ++i) {
		// Calculamos rango de primos
		begin = count == min? count: ++count;
		end = (count + size)>max? max: count+size;
		count += size;
		printf("hola\n");
		// Cerramos los pipe innecesarios
		close(fdE[i][1]);

		// Creamos el pipe del esclavo
		pipe(fdE[i]);

		if ((pid = fork()) < 0) {
			perror("\nError en fork"); // En caso error
			exit(EXIT_FAILURE);
		} else if(pid == 0) { // Proceso hijo (Esclavo)
			printf("hijo\n");
			dup2(fdE[i][0], STDIN_FILENO);
			dup2(fdM[1], STDOUT_FILENO);
			printf("hijo\n");
			if (execl("./esclavo", "esclavo", NULL) < 0) {
				perror("Error al ejecutar el comando.");
			}	
		} else { // Proceso padre (Maestro)
			// No necesitamos leer en el esclavo
			close(fdE[i][0]);

			// Mandamos los datos
			write(fdE[i][1], &begin, sizeof(int));
			write(fdE[i][1], &end, sizeof(int));
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


