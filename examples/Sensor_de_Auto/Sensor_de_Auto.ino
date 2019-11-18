//Incluyo la libreria de manejo de la estacion Estacionamiento.
#include <LibEstacionamiento.h>


void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() {

  //Leer sensor de auto 1 y guardar en estado_auto1.
  estado_auto1 = sensor_auto1.leer();
  
  if(estado_auto1 == ACTIVADO)
  {
    mostrar_cartel("Sensor Auto 1 ACTIVADO \n");
  }
  else
  {
    mostrar_cartel("Sensor Auto 1 DESACTIVADO \n");
  }

  //Leer sensor de auto 2 y guardar en estado_auto2.
  estado_auto2 = sensor_auto2.leer();
  
  if(estado_auto2 == ACTIVADO)
  {
    mostrar_cartel("Sensor Auto 2 ACTIVADO \n");
  }
  else
  {
    mostrar_cartel("Sensor Auto 2 DESACTIVADO \n");
  }
  
  //Leer sensor de auto 3 y guardar en estado_auto3.
  estado_auto3 = sensor_auto3.leer();
  
  if(estado_auto3 == ACTIVADO)
  {
    mostrar_cartel("Sensor Auto 3 ACTIVADO \n");
  }
  else
  {
    mostrar_cartel("Sensor Auto 3 DESACTIVADO \n");
  }

  //Leer sensor de auto 4 y guardar en estado_auto4.
  estado_auto4 = sensor_auto4.leer();
  
  if(estado_auto4 == ACTIVADO)
  {
    mostrar_cartel("Sensor Auto 4 ACTIVADO \n");
  }
  else
  {
    mostrar_cartel("Sensor Auto 4 DESACTIVADO \n");
  }

  mostrar_cartel("******************************** \n");

  //Espera de medio segundo.
  delay(500);

}
