//Incluyo la libreria de manejo de la estacion Estacionamiento.
#include <LibEstacionamiento.h>


void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() {

  //Leer sensor barrera de entrada y guardar en estado_entrada.
  estado_entrada = sensor_barrera_entrada.leer();
  
  if(estado_entrada == ACTIVADO)
  {
    mostrar_cartel("Sensor entrada ACTIVADO \n");
  }
  else
  {
    mostrar_cartel("Sensor entrada DESACTIVADO \n");
  }


  //Leer sensor barrera de entrada y guardar en estado_entrada.
  estado_salida = sensor_barrera_salida.leer();
  
  if(estado_salida == ACTIVADO)
  {
    mostrar_cartel("Sensor salida ACTIVADO \n");
  }
  else
  {
    mostrar_cartel("Sensor salida DESACTIVADO \n");
  }

  mostrar_cartel("*************************************** \n");

  //Espera de medio segundo.
  delay(500);

}
