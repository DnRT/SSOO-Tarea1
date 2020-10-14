# SSOO-Tarea1
# Para comenzar se agregan las librerias necesarias para poder manejar las señales y poder utilizarlas.
# Luego se inicializan 2 metodos, los cuales son las acciones dependiendo de la señal recibida, siendo salir() la que controla el tiempo de ejecucion del programa y hora() el que muestra el tiempo actual de ejecucion.
# En main se genera y almacena el PID para poder ser utilizado mas adelante, ademas de tener un bucle while con una variable llamada ctrC, esta almacena la cantidad de veces que se repite la accion del control + C llegando a un maximo de 1, es decir al momento que llegue a 2 termina el programa.
# Para profundizar en los metodos solo hay que entender algo, salir solo aumenta el contador anterior para poder decidir cuando terminar el programa de la forma en que se especifico en el punto anterior.
# En cambio el metodo hora, el cual se diferencia por tener "más complejidad" que el anterior metodo, recolecta la hora actual del sistema y es mostrado (a traves de numeros) con el siguiente formato:
# Dia/Mes/Año Hora:Minuto:Segundo