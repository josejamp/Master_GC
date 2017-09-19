#pragma once
#include "ObjetoCompuesto.h"
#include "InterruptorLinterna.h"
class Linterna :
	public ObjetoCompuesto
{
public:
	Linterna();
	~Linterna();
	void presionaInterruptor();
	void mueveLinternaAlante();
	void mueveLinternaAtras();
	void giraIzqda();
	void giraDcha();
	void dibuja();
protected:
	bool _encendida;
	InterruptorLinterna* interruptor;
};

