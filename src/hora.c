//Librerias necesarias para ejecutar el programa
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
void salir(); //Inicializacion del controlador de salida
void hora(); //Programa captura y muestra por pantalla la hora actual del sistema
char output[128]; //Arreglo necesario para poder almacenar la fecha y hora
int ctrC=0; //Contador de recepcion de señal de salida
int main(){
    pid_t test=getpid(); //Nos retorna el numero del proceso para poder utilizarlo remotamente
    printf("Programa hora ejecutandose. PIR:%d\n", test); //Muestra el PID
    printf("Listo para recibir la señal SIGUSR1.\n");
    signal(SIGINT, salir);//Este se limita a recibir la señal de salida
    while(ctrC<2){//Bucle para poder controlar y repetir la señal de SIGUR1
        signal(SIGUSR1,hora);//Este es la reacción al recibir la señal de usuario
        sleep(0);
    }
    return 0;
}
void salir(){//Esta funcion simplemente aumenta en 1 el contador para la salida del programa
    ctrC++;
}
void hora(){
    time_t tiempo=time(0);//Variable que recopila la fecha y hora actual
    struct tm *tlocal=localtime(&tiempo);//Estructura para poder darle un mejor manejo a la variable anterior
    strftime(output,128, "%d/%m/%y %H:%M:%S",tlocal);//Esta funcion da un orden en particular a la fecha y hora la cual es dia/mes/año hora:minutos:segundos
    printf("Señal SIGUSR1 recibida: %s\n",output); //El resultado de todo, si recibe la señal indicada
}