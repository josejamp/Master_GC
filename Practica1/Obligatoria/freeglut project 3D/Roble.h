#ifndef Roble_H_
#define Roble_H_

#include "Tronco.h"
#include "CopaEsferica.h"

class Roble{

	protected:
		Tronco* _tronco;
		CopaEsferica* _copaEsferica;


	public:
		Roble();
		~Roble();
		void dibuja();


};

#endif

