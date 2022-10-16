#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int SEGUNDOS=30;
 
void manejadorInt () {
	printf("\n ALARMA CANCELADA \n");
	alarm(0); 
}

void manejadorAlr () {
	printf("\n FIN ALARMA \n");
        exit(1);
}

void manejadorQuit () {
	signal (SIGALRM, SIG_IGN);
        printf("\n ALARMA FINALIZADA \n");
}
 
int main(void) {

   alarm(SEGUNDOS);
   signal(SIGINT, manejadorInt);
   signal(SIGALRM, manejadorAlr);
   signal(SIGQUIT, manejadorQuit); 
   while (1);
}

