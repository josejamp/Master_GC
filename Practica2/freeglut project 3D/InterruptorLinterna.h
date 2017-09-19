#pragma once
#include "ObjetoCompuesto.h"
class InterruptorLinterna :
	public ObjetoCompuesto
{
public:
	InterruptorLinterna();
	~InterruptorLinterna();
	void enciende();
	void apaga();
};

