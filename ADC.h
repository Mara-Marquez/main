#ifndef ADC_H
#define ADC_H

#include <Arduino.h>

class ADCManager
{
public:

    void iniciar();

    uint16_t leer(uint8_t canal);
};

#endif