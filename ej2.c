#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void manejadorInt(int num) {
	printf("SIGINT recibido/n");
	alarm(5);
} 

void manejadorAlr(int num) {
	printf("/n Fin/ n");
	exit(1);
}
int main(void) {
   signal(2, manejadorInt);
   signal(SIGALRM, manejadorAlr);
   alarm(5);
   while (1);
}


