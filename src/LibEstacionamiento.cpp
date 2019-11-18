/*
  LibEstacionamientoC.cpp - Libreria para el manejo de la 
  estacion del cruce de calles con semaforo.
  Javier Sankowicz.
*/

#include "Arduino.h"
#include "LibEstacionamiento.h"


/* ************ Funciones de la clase LuzAuto ************ */

LuzAuto::LuzAuto(int pin_rojo,int pin_verde)
{
  pinMode(pin_rojo, OUTPUT);
  pinMode(pin_verde, OUTPUT);
  _pin_rojo = pin_rojo;
  _pin_verde = pin_verde;
  digitalWrite(_pin_rojo,LOW);
  digitalWrite(_pin_verde,LOW);
}

void LuzAuto::encender(int luz)
{
  switch(luz)
  {
	  case ROJO:
	  digitalWrite(_pin_rojo,HIGH);
	  break;
	  case VERDE:
	  digitalWrite(_pin_verde,HIGH);
	  break;
	  default:
	  break;
  }
}

void LuzAuto::apagar(int luz)
{
	switch(luz)
	{
		case ROJO:
		digitalWrite(_pin_rojo,LOW);
		break;
		case VERDE:
		digitalWrite(_pin_verde,LOW);
		break;
		default:
		break;
  }
}

/* ********************************************************** */

/* ************ Funciones de la clase SensorBarrera ************ */

SensorBarrera::SensorBarrera(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int SensorBarrera::leer()
{
	return(!digitalRead(_pin));
}

void SensorBarrera::esperar(int estado)
{
	while(leer()!=estado);
}

/* *********************************************************** */

/* ************ Funciones de la clase Barrera ************** */




/* ********************************************************* */

/* ************ Funciones de la clase SensorAuto ************ */

SensorAuto::SensorAuto(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int SensorAuto::leer()
{
	return(!digitalRead(_pin));
}

void SensorAuto::esperar(int estado)
{
	while(leer()!=estado);
}

/* *********************************************************** */

/* ************ Funciones de la clase Pulsador ************** */

Pulsador::Pulsador(int pin)
{
	pinMode(pin,INPUT);
	_pin=pin;
}

int Pulsador::leer()
{
	return(digitalRead(_pin));
}

void Pulsador::esperar(int estado)
{
	while(leer()!=estado);
}

/* ********************************************************* */


/* ************ Funciones para el manejo de los  servos de las barreras************** */
Servo ServoEntrada;
Servo ServoSalida;

void subir_barrera_entrada(){
  ServoEntrada.write(anguloArriba_Entrada);
}

void bajar_barrera_entrada(){
  ServoEntrada.write(anguloAbajo_Entrada);
}

void subir_barrera_salida(){
  ServoSalida.write(anguloArriba_Salida);
}

void bajar_barrera_salida(){
  ServoSalida.write(anguloAbajo_Salida);
}

void inicializar_barreras(){
	ServoEntrada.attach(pin_Barrera_Entrada);
	ServoSalida.attach(pin_Barrera_Salida);
	bajar_barrera_entrada();
	bajar_barrera_salida();	
}

/* ********************************************************************************* */

/* ************Ingresar numero por puerto serie************** */

int ingresar_numero()   //devuelve un entero que va de -32768 a 32767
{
  String readString;
  
  while(!(Serial.available()>0));

  while(Serial.available()>0)
  {
    char c = Serial.read();
    readString += c;
    delay(2);
  }

  int number = readString.toInt();

  return number;
}
/* ********************************************************* */

/* ************Funciones imprimir texto********************* */

void mostrar_cartel(char *str)
{
	Serial.print(str);
	Serial.print("");
}

void mostrar_numero(int num)
{
	Serial.println(num);
}

/* ********************************************************* */

/* *****************Inicializacion************************** */
void inicializar_sistema()
{
	Serial.begin(9600);
	//inicializar_barreras();
}
/* ********************************************************* */

/* ******************Finalizacion*************************** */
void finalizar()
{
	while(1);
}
/* ********************************************************* */

//Variables para manejo de sensores y pulsadores.
int estado_entrada=DESACTIVADO;
int estado_salida=DESACTIVADO;
int estado_auto1=DESACTIVADO;
int estado_auto2=DESACTIVADO;
int estado_auto3=DESACTIVADO;
int estado_auto4=DESACTIVADO;
int estado_pulsador=NO_PRESIONADO;
int numero_ingresado=0;


//Variables elementos del sistema
LuzAuto luz_auto1(pin_Rojo1,pin_Verde1);
LuzAuto luz_auto2(pin_Rojo2,pin_Verde2);
LuzAuto luz_auto3(pin_Rojo3,pin_Verde3);
LuzAuto luz_auto4(pin_Rojo4,pin_Verde4);

Pulsador pulsador(pin_Pulsador);

SensorBarrera sensor_barrera_entrada(pin_Sensor_Entrada);
SensorBarrera sensor_barrera_salida(pin_Sensor_Salida);

SensorAuto sensor_auto1(pin_Sensor_Auto1);
SensorAuto sensor_auto2(pin_Sensor_Auto2);
SensorAuto sensor_auto3(pin_Sensor_Auto3);
SensorAuto sensor_auto4(pin_Sensor_Auto4);