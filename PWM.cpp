#include "PWM.h"
#include <Arduino.h>

void PWM::iniciar()
{
    DDRB |= (1 << PB1);  // Pin 9 = OC1A

    TCCR1A =
        (1 << COM1A1) |
        (1 << WGM11);

    TCCR1B =
        (1 << WGM13) |
        (1 << WGM12) |
        (1 << CS11);

    ICR1 = 799;
}

void PWM::setDuty(uint8_t duty)
{
    OCR1A = map(duty, 0, 255, 0, ICR1);
}