/*
  LibEstacionamientoC.h - Libreria para el manejo de la 
  estacion del Estacionamiento.
  Javier Sankowicz.
*/
#ifndef LibEstacionamiento_h
#define LibEstacionamiento_h

#include "Arduino.h"
#include <Servo.h>

#define ROJO 0
#define VERDE 1

#define PRESIONADO LOW
#define NO_PRESIONADO HIGH

#define ACTIVADO LOW
#define DESACTIVADO HIGH

#define REPETIR(X) for(int i=0;i<X;i++)

const int pin_Rojo1 = 2;
const int pin_Verde1 = 3;
const int pin_Rojo2 = 4;
const int pin_Verde2 = 5;
const int pin_Rojo3 = 8;
const int pin_Verde3 = A5;
const int pin_Rojo4 = 12;
const int pin_Verde4 = 11;

const int pin_Barrera_Salida = 9;
const int anguloArriba_Salida = 130;
const int anguloAbajo_Salida = 35;

const int pin_Barrera_Entrada = 10;
const int anguloArriba_Entrada = 55;
const int anguloAbajo_Entrada = 150;

const int pin_Sensor_Entrada = A3;
const int pin_Sensor_Salida = A2;

const int pin_Sensor_Auto1 = 6;
const int pin_Sensor_Auto2 = 7;
const int pin_Sensor_Auto3 = A0;
const int pin_Sensor_Auto4 = A1;

const int pin_Pulsador = A4;

extern Servo ServoEntrada;
extern Servo ServoSalida;

extern void subir_barrera_entrada();
extern void subir_barrera_salida();
extern void bajar_barrera_entrada();
extern void bajar_barrera_salida();
extern void inicializar_barreras();

extern void mostrar_cartel(char *str);
extern void mostrar_numero(int num);
extern int ingresar_numero();
extern void inicializar_sistema();
extern void finalizar();


//Variables para manejo de sensores y pulsadores.
extern int estado_entrada;
extern int estado_salida;
extern int estado_auto1;
extern int estado_auto2;
extern int estado_auto3;
extern int estado_auto4;
extern int estado_pulsador;
extern int numero_ingresado;

//Variable contador
extern int contador;


//sino hacer una clase para luces y habria 8 instancias en vez de 4.
class LuzAuto
{
	public:
		LuzAuto(int pin_rojo,int pin_verde);
		void encender(int luz);
		void apagar(int luz);
	private:
		int _pin_rojo;
		int _pin_verde;
};

class SensorBarrera
{
	public:
		SensorBarrera(int pin);
		int leer();
		void esperar(int estado);
	private:
		int _pin;
};

class SensorAuto
{
	public:
		SensorAuto(int pin);
		int leer();
		void esperar(int estado);
	private:
		int _pin;
	
};



class Pulsador
{
	public:
		Pulsador(int pin);
		int leer();
		void esperar(int estado);
	private:
		int _pin;
};


//Variables elementos del sistema
extern LuzAuto luz_auto1;
extern LuzAuto luz_auto2;
extern LuzAuto luz_auto3;
extern LuzAuto luz_auto4;
extern Pulsador pulsador;
extern SensorBarrera sensor_barrera_entrada;
extern SensorBarrera sensor_barrera_salida;
extern SensorAuto sensor_auto1;
extern SensorAuto sensor_auto2;
extern SensorAuto sensor_auto3;
extern SensorAuto sensor_auto4;

#endif

