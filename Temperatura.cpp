

#include "Temperatura.h"

Temperatura::Temperatura(uint8_t pin)
: dht(pin, DHT11)
{
}

void Temperatura::iniciar()
{
    dht.begin();
}

float Temperatura::leer()
{
    return dht.readTemperature();
}