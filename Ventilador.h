#ifndef VENTILADOR_H
#define VENTILADOR_H

#include "PWM.h"

struct EstadoVentilador
{
    int pwm;
    int porcentaje;
};

class Ventilador
{
private:

    int pin;

    PWM controlPWM;

public:

    Ventilador(int pin);

    void iniciar();

    int controlar(
        float temperatura,
        float setpoint
    );
};

#endif