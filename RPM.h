#ifndef RPM_H
#define RPM_H

#include <Arduino.h>

class RPM
{
private:

    int pinLedIR;
    int pinSensor;

    int contadorFlancos;

    bool estadoAnteriorAlto;

    unsigned long tiempoAnterior;

    float rpm;

public:

    RPM(int ledIR, int sensor);

    void iniciar();

    void actualizar();

    float obtenerRPM();
};

#endif