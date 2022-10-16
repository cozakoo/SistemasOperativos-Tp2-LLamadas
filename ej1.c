/*
 a. El script lo que hace es una vez iniciado queda en espera a que le manden una señal, especificamente un SIGNAL. Una vez que le mandan un SIGNAL se ejecutara el manejador donde mostrara un mensaje por consola que informara que se le recibio esa señal. Nuevamente quedara esperando a que le manden una señal hasta que le manden tres señales en total y posteriormente finalizara su ejecucion.
 
  b) 
  
  i) Con el script anterior es posible matarlo mandando la señal de ‘ctrl+c’. Tiene que ser tres veces ya que asi lo dispone el manejador. Con el siguiente script modificado es posible matar al programa si dejamos el "exit(1)". Ya que una vez que se enviara un SIGINT finalizaria el programa despues de un envio de señal "ctrl+c". De lo contrario, si comentaramos el exit(1)" la única forma de matar al programa seria entrando a traves de otra terminal y enviarle un 'kill <2|SIGKILL> <numero_pid>
  
  ii) El manejador no se pierde, porque el codigo seguira siendo el mismo.
  
  iii) No, no es posible capturar un SIGKILL. Porque al momento de mandarle un SIGKILL el script finalizara sin importar lo que se quiera hacer con la señal.
  
     
*/ 

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int cant = 0;
void manejador(int num) {
   printf("Se recibió SIGINT\n");
   
   /*
   cant++;
   if (cant == 3) {
      printf("Finalizo mi ejecución\n");
      exit(1);
   }
   */
}
int main(void) {
   signal(SIGINT, manejador);
   while (1);
}
