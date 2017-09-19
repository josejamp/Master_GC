#ifndef Pino_H_
#define Pino_H_

#include "Tronco.h"
#include "CopaCono.h"

class Pino{

	protected:
		Tronco* _tronco;
		CopaCono* _copaConoAbajo;
		CopaCono* _copaConoArriba;


	public:
		Pino();
		~Pino();
		void dibuja();

};

#endif