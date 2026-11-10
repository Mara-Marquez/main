//BIDNN
#include "Temporizador.h"
#include <avr/interrupt.h>

volatile bool segundoTranscurrido = false;

Temporizador::Temporizador()
{
}

void Temporizador::iniciar()
{
    cli(); // Deshabilita interrupciones

    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    // Modo CTC
    TCCR1B |= (1 << WGM12);

    // Prescaler 1024
    TCCR1B |= (1 << CS12) | (1 << CS10);

    // 16 MHz / 1024 = 15625 Hz
    // Para 1 segundo:
    OCR1A = 15624;

    // Habilitar interrupción por comparación
    TIMSK1 |= (1 << OCIE1A);

    sei(); // Habilita interrupciones
}

bool Temporizador::cadaSegundo()
{
    if(segundoTranscurrido)
    {
        segundoTranscurrido = false;
        return true;
    }

    return false;
}

ISR(TIMER1_COMPA_vect)
{
    segundoTranscurrido = true;
}
