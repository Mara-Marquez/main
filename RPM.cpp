#include "RPM.h"
#include "ADC.h"
#include <avr/io.h>
#include <Arduino.h>
#define UMBRAL_LUZ 3
#define INTERVALO 3000
ADCManager adc;
RPM::RPM(int ledIR, int sensor)
{
	pinLedIR = ledIR;
	pinSensor = sensor;
	contadorFlancos = 0;
	rpm = 0;
	tiempoAnterior = 0;
	estadoAnteriorAlto = false;
}
void RPM::iniciar()
{
	// Pin D3 como salida
	DDRD |= (1 << DDD3);
	// Encender LED IR
	PORTD |= (1 << PORTD3);
	adc.iniciar();
	int valorInicial = adc.leer(0);
	estadoAnteriorAlto =
    	(valorInicial > UMBRAL_LUZ);
}
void RPM::actualizar()
{
	int valorActual =
    	adc.leer(0);
	bool estadoActualAlto =
    	(valorActual > UMBRAL_LUZ);
	if (estadoActualAlto != estadoAnteriorAlto)
	{
    	


