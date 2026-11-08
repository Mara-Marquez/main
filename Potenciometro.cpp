#include "Potenciometro.h"
#include "ADC.h"
#include <Arduino.h>

#define MINTEMP 22.0
#define MAXTEMP 30.0
ADCManager adc;


void Potenciometro::iniciar()
{
    adc.iniciar();
}

Potenciometro::Potenciometro(int pin)
{
    this->pin = pin;
}

float Potenciometro::obtenerSetpoint()
{
    int valor = adc.leer(3);

    //Serial.print("ADC = ");
    //Serial.println(valor);
    return MINTEMP +
           (valor * (MAXTEMP - MINTEMP) / 1023.0);
}