#include "RPM.h"
//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
#define UMBRAL_LUZ 4
#define INTERVALO 3000

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
    pinMode(pinLedIR, OUTPUT);

    digitalWrite(pinLedIR, HIGH);

    int valorInicial =
        analogRead(pinSensor);

    estadoAnteriorAlto =
        (valorInicial > UMBRAL_LUZ);
}

void RPM::actualizar()
{
    int valorActual =
        analogRead(pinSensor);

    bool estadoActualAlto =
        (valorActual > UMBRAL_LUZ);

    if(estadoActualAlto != estadoAnteriorAlto)
    {
        delayMicroseconds(50);

        int valorVerificacion =
            analogRead(pinSensor);

        if(
            (valorVerificacion > UMBRAL_LUZ)
            ==
            estadoActualAlto
          )
        {
            contadorFlancos++;

            estadoAnteriorAlto =
                estadoActualAlto;
        }
    }

    unsigned long tiempoActual =
        millis();

    if(
        tiempoActual - tiempoAnterior
        >= INTERVALO
      )
    {
        float revoluciones =
            (float)contadorFlancos
            / 14.0;

        rpm =
            revoluciones * 20.0;

        Serial.print("RPM: ");
        Serial.println(rpm);

        contadorFlancos = 0;

        tiempoAnterior =
            tiempoActual;
    }
}

float RPM::obtenerRPM()
{
    return rpm ;
}