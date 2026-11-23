#include "Watchdog.h"
#include <avr/wdt.h>

void Watchdog::iniciar()
{
    wdt_enable(WDTO_2S);
}

void Watchdog::reset()
{
    wdt_reset();
}

void Watchdog::reiniciarSistema()
{
    wdt_enable(WDTO_15MS);

    while(true)
    {
    }
}