#ifndef Bosque_H_
#define Bosque_H_

#include "Abeto.h"
#include "Pino.h"
#include "Roble.h"
#include "Alamo.h"


class Bosque
{

	private:
		Abeto* abeto;
		Pino* pino;
		Roble* roble;
		Alamo* alamo;

		public:
			Bosque();
			~Bosque();
			void dibuja();
};

#endif