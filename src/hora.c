#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
void salir();
void hora();
char output[128];
int ctrC=0;
int main(){
    pid_t test=getpid();
    printf("Programa hora ejecutandose. PIR:%d\n", test);
    printf("Listo para recibir la señal SIGUSR1.\n");
    signal(SIGINT, salir);
    while(ctrC<2){
        signal(SIGUSR1,hora);
        sleep(0);
    }
    return 0;
}
void salir(){
    ctrC++;
}
void hora(){
    time_t tiempo=time(0);
    struct tm *tlocal=localtime(&tiempo);
    strftime(output,128, "%d/%m/%y %H:%M:%S",tlocal);
    printf("Señal SIGUSR1 recibida: %s\n",output); 
}