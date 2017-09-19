#ifndef Roble_H_
#define Roble_H_

#include "Tronco.h"

#include "ObjetoCompuesto.h"

class Roble : public ObjetoCompuesto{

	protected:
		GLfloat _especular;

	public:
		Roble();
		~Roble();
		void dibuja();
		void cambiaEspecular(GLfloat esp);

};

#endif

