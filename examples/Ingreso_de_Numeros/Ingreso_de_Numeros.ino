//Incluyo la libreria de manejo de la estacion Estacionamiento.
#include <LibEstacionamiento.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() {
  //Imprimir un mensaje por pantalla.
  mostrar_cartel("Ingresar un numero: \n");
    
  //Ingresar un numero y almacenarlo como entero.
  numero_ingresado = ingresar_numero();

  //Imprimir mensaje por pantalla.
  mostrar_cartel("Numero ingresado: ");    

  //Imprimir el numero ingresado por pantalla.
  mostrar_numero(numero_ingresado);
  
}
