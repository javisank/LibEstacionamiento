//Incluyo la libreria de manejo de la estacion Estacionamiento.
#include <LibEstacionamiento.h>


void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() {

  //Leer el estado del pulsador y almacenarlo en la variable estado_pulsador.
  estado_pulsador = pulsador.leer();
  
  if(estado_pulsador == PRESIONADO)
  {
    mostrar_cartel("Pulsador PRESIONADO\n");
  }
  else
  {
    mostrar_cartel("Pulsador NO PRESIONADO\n");
  }

  mostrar_cartel("----------------------------------------------\n");
  //Espera de 500 mSeg.
  delay(500);
}
