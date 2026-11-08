#ifndef POTENCIOMETRO_H
#define POTENCIOMETRO_H

class Potenciometro
{
private:
    int pin;

public:
    Potenciometro(int pin);
     void iniciar();

    float obtenerSetpoint();
};

#endif