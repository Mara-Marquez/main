#ifndef TEMPERATURA_H
#define TEMPERATURA_H

#include <DHT.h>

class Temperatura
{
private:
    DHT dht;

public:
    Temperatura(uint8_t pin);

    void iniciar();

    float leer();
};

#endif