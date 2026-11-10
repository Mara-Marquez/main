#include "Ventilador.h"
#include "PWM.h"
#include <Arduino.h>

#define MAXTEMP 30.0
PWM controlPWM;
Ventilador::Ventilador(int pin)
{
    this->pin = pin;
}

void Ventilador::iniciar()
{
   
    controlPWM.iniciar();
}

int Ventilador::controlar(float temperatura,
                          float setpoint)
{
    int pwm;

    if (temperatura < setpoint)
    {
        pwm = 0;
    }
    else
    {
        //de un rango a otros
        pwm = map(
            (int)(temperatura * 10),
            (int)(setpoint * 10),
            MAXTEMP * 10,
            80,
            255
        );
//limita el resultado 
        pwm = constrain(pwm, 80, 255);
    }

    controlPWM.setDuty(pwm);

    return pwm;
}