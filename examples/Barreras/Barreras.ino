//Incluyo la libreria de manejo de la estacion Estacionamiento.
#include <LibEstacionamiento.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
  
  //Función de inicialización de las barreras.
  inicializar_barreras();
}

void loop() {
  
  //Subo la Barrera de Entrada
  subir_barrera_entrada();

  //Espera de 1 segundo
  delay(1000);

  //Subo la Barrera de Salida
  subir_barrera_salida();

  //Espera de 1 segundo
  delay(1000);

  //Bajo la Barrera de Entrada
  bajar_barrera_entrada();

  //Espera de 1 segundo
  delay(1000);

  //Bajo la Barrera de Salida
  bajar_barrera_salida();

  //Espera de 1 segundo
  delay(1000);  
}



