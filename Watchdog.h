#ifndef WATCHDOG_H
#define WATCHDOG_H

#include <Arduino.h>

class Watchdog
{
public:

    void iniciar();

    void reset();
        void reiniciarSistema();

};

#endif