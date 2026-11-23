//COD CHIDO
#include "Temperatura.h"
#include "Potenciometro.h"
#include "Ventilador.h"
#include "Pantalla.h"
#include "Temporizador.h"
#include "Watchdog.h"
#include "RPM.h"

Temperatura sensorTemp(2);

Potenciometro pot(A3);

Ventilador ventilador(9);

Pantalla pantalla;

Temporizador timer;
Watchdog watchdog;
RPM sensorRPM(3, A0);

void setup()
{
   
    Serial.begin(9600);

   // Serial.println("SETUP INICIADO");

    pantalla.iniciar();

    pantalla.mostrarMensaje(
        "Iniciando Sistema",
        "OK..."
    );

    delay(3000);

    sensorTemp.iniciar();
    ventilador.iniciar();
    pot.iniciar();
    sensorRPM.iniciar();

    watchdog.iniciar();

   // Serial.println("SETUP TERMINADO");
}
void loop()
{
    watchdog.reset();
    float temperatura =
        sensorTemp.leer();

    float setpoint =
        pot.obtenerSetpoint();

 if (isnan(temperatura))
{
    pantalla.mostrarMensaje(
        "ERROR DHT11",
        "Reiniciando..."
    );

    delay(1000);

    watchdog.reiniciarSistema();
}

    int pwm =
        ventilador.controlar(
            temperatura,
            setpoint
        );
    int porcentajePWM =
    (pwm * 100) / 255;
    sensorRPM.actualizar();
    int rpm =
(int)sensorRPM.obtenerRPM();

  pantalla.mostrarDatos(
    temperatura,
    setpoint,
    rpm,
    porcentajePWM
);
}