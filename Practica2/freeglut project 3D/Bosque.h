#ifndef Bosque_H_
#define Bosque_H_

#include "Abeto.h"
#include "Pino.h"
#include "Roble.h"
#include "Alamo.h"
#include "ObjetoCompuesto.h"


class Bosque : public ObjetoCompuesto
{

	private:
		Abeto* abeto;
		Pino* pino;
		Roble* roble;
		Alamo* alamo;

		public:
			Bosque();
			~Bosque();
			void cambiaEspecularRoble(GLfloat esp);
};

#endif