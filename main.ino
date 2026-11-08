
#include "Temperatura.h"
#include "Potenciometro.h"
#include "Ventilador.h"
#include "Pantalla.h"
#include "Temporizador.h"

Temperatura sensorTemp(2);

Potenciometro pot(A3);

Ventilador ventilador(9);

Pantalla pantalla;

Temporizador timer;

void setup()
{
    Serial.begin(9600);

    sensorTemp.iniciar();

    ventilador.iniciar();
    pot.iniciar();

    pantalla.iniciar();
}
void loop()
{
    float temperatura =
        sensorTemp.leer();

    float setpoint =
        pot.obtenerSetpoint();

    if (isnan(temperatura))
    {
        pantalla.mostrarError();
        return;
    }

    int pwm =
        ventilador.controlar(
            temperatura,
            setpoint
        );
    int porcentajePWM =
    (pwm * 100) / 255;
  pantalla.mostrarDatos(
    temperatura,
    setpoint,
    0,
    porcentajePWM
);
}