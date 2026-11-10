#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H


#include <avr/io.h>


class Temporizador
{
public:
    Temporizador();
    void iniciar();
    bool cadaSegundo();


private:
    volatile bool banderaSegundo;
};


#endif
