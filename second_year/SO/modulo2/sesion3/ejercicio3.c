// Ejercicio 3

#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<errno.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {
	int nprocs = 3;
	pid_t childpid;

	printf("I am your Grandfather: %d\n", getpid());

	/*
	Jerarquía de procesos tipo 1
	*/
	for (int i=1; i < nprocs; i++) {
		if ((childpid= fork()) == -1) {
			fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
			exit(-1);
		}
		printf("Father created: %d and my father: %d\n", getpid(), getppid());
		if (childpid) {
			break;
		}
	}
		
	/*
	Jerarquía de procesos tipo 2
	*/
	for (int i=1; i < nprocs; i++) {
		if ((childpid= fork()) == -1) {
			fprintf(stderr, "Could not create child %d: %s\n",i,strerror(errno));
			exit(-1);
		}
		printf("Child created: %d and my father: %d\n", getpid(), getppid());
		if (!childpid) {
			break;
		}
	}

	return 0;
}
