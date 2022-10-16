/*

 a. Lo que hace el siguiente script es consultar si se trata de un proceso padre o de un proceso hijo. Si el valor del 'fork()' devuelve 0 quiere decir que se ejecutara el codigo del hijo, que este codigo lo que hace es abrir una nueva ventana Firefox. Si el valor del fork es distinto de 0 quiere decir que es ejecutado por el padre y entra en el codigo del padre, que lo que hace es imprimir que es el proceso padre y hace un waitpid que quiere decir que espera a que el hijo termine su ejecucion para terminar su proceso.

*/

// b.

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#define TRUE 1
char*comando[3]={"/bin/ls","-ltr", NULL};


int main() {
	int status;

	if (fork() != 0) /* Código del padre */
	{
		printf("\nPADRE\n");
		waitpid(-1, &status,0);
	}
	else
		/* Código del hijo */
		execv(comando[0], comando);
	return 0;
}

