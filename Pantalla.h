#ifndef PANTALLA_H
#define PANTALLA_H

#include <Adafruit_SSD1306.h>

class Pantalla
{
private:
    Adafruit_SSD1306 display;

public:
    Pantalla();

    bool iniciar();

    void mostrarInicio(float setpoint);

    void mostrarDatos(
        float temp,
        float setpoint,
        int rpm,
        int pwm
    );

    void mostrarError();
};

#endif