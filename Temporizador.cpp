#include "Temporizador.h"
#include <Arduino.h>

Temporizador::Temporizador()
{
    anterior = 0;
}

bool Temporizador::cadaSegundo()
{
    if(millis() - anterior >= 1000)
    {
        anterior = millis();
        return true;
    }

    return false;
}