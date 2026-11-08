#include "Pantalla.h"
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

Pantalla::Pantalla()
: display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1)
{
}

bool Pantalla::iniciar()
{
    return display.begin(
        SSD1306_SWITCHCAPVCC,
        SCREEN_ADDRESS
    );
}

void Pantalla::mostrarError()
{
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0,0);
    display.println("Error Sensor");

    display.display();
}

void Pantalla::mostrarDatos(
    float temp,
    float setpoint,
    int rpm,
    int pwm)
{
    display.clearDisplay();

    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    display.setCursor(0,0);
    display.print("Temp:");
    display.print(temp,1);
    display.println(" C");

    display.setCursor(0,15);
    display.print("Obj:");
    display.print(setpoint,1);
    display.println(" C");

    display.setCursor(0,30);
    display.print("RPM:");
    display.println(rpm);

    display.setCursor(0,45);
display.print("PWM:");
display.print(pwm);
display.println("%");

    display.display();
}