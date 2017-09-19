#ifndef Iman_H_
#define Iman_H_

#include "Malla.h"
class Iman : public Malla {

	protected:
		int _nQ; //numero de veces en el que se divide la parte circular
		int _rInt; // radio interno
		int _rExt; //radio externo
		int _h; //altura

	public:
		Iman(int nQ, int rInt, int rExt, int h);
		~Iman();
		void dibuja();

};

#endif
