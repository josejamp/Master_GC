#ifndef Abeto_H_
#define Abeto_H_

#include "Tronco.h"
#include "CopaCono.h"

class Abeto{

	protected:
		Tronco* _tronco;
		CopaCono* _copaCono;


	public:
		Abeto();
		~Abeto();
		void dibuja();


};

#endif
