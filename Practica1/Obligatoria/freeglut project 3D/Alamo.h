#ifndef Alamo_H_
#define Alamo_H_

#include "Tronco.h"
#include "CopaEsferica.h"

class Alamo{

	protected:
		Tronco* _tronco;
		CopaEsferica* _copaEsfericaIzqda;
		CopaEsferica* _copaEsfericaDcha;


	public:
		Alamo();
		~Alamo();
		void dibuja();


};

#endif


