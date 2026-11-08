#ifndef PWM_H
#define PWM_H

#include <Arduino.h>

class PWM
{
public:

    void iniciar();

    void setDuty(uint8_t duty);
};

#endif