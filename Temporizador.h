#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H

class Temporizador
{
private:
    unsigned long anterior;

public:
    Temporizador();

    bool cadaSegundo();
};

#endif