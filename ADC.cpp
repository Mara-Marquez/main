#include "ADC.h"

void ADCManager::iniciar()
{
    ADMUX = (1 << REFS0);

    ADCSRA =
        (1 << ADEN)  |
        (1 << ADPS2) |
        (1 << ADPS1) |
        (1 << ADPS0);
}

uint16_t ADCManager::leer(uint8_t canal)
{
    ADMUX =
        (ADMUX & 0xF0) |
        (canal & 0x0F);

    ADCSRA |= (1 << ADSC);

    while (ADCSRA & (1 << ADSC));

    return ADC;
}