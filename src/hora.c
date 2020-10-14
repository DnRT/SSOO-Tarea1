#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    pid_t test=getpid();
    printf("Programa hora ejecutandose. PIR:%d\n", test);
    printf("Listo para recibir la señal SIGUSR1.\n");
    
    return 0;
}