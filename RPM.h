#ifndef RPM_H
#define RPM_H
#include <stdint.h>
class RPM
{
private:
	uint8_t pinLedIR;
	uint8_t canalADC;
	int contadorFlancos;
	bool estadoAnteriorAlto;
	unsigned long tiempoAnterior;
	float rpm;
public:
	RPM(uint8_t ledIR, uint8_t canalADC);
	void iniciar();
	void actualizar();
	float obtenerRPM();
};
#endif


