//Incluyo la libreria de manejo de la estacion Estacionamiento.
#include <LibEstacionamiento.h>

void setup() {
  //Función de inicialización del sistema.
  inicializar_sistema();
}

void loop() 
{
  luz_auto1.encender(ROJO);
  luz_auto1.encender(VERDE);

  luz_auto2.encender(ROJO);
  luz_auto2.encender(VERDE);

  luz_auto3.encender(ROJO);
  luz_auto3.encender(VERDE);

  luz_auto4.encender(ROJO);
  luz_auto4.encender(VERDE);


  delay(1000);    //espera de 1000 mSeg o 1 Seg.

  luz_auto1.apagar(ROJO);
  luz_auto1.apagar(VERDE);

  luz_auto2.apagar(ROJO);
  luz_auto2.apagar(VERDE);

  luz_auto3.apagar(ROJO);
  luz_auto3.apagar(VERDE);

  luz_auto4.apagar(ROJO);
  luz_auto4.apagar(VERDE);

  delay(1000);    //espera de 1000 mSeg o 1 Seg.
}

