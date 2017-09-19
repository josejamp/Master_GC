#ifndef Faro_H_
#define Faro_h_


#include "ObjetoCompuesto.h"
class Faro :
	public ObjetoCompuesto
{

protected:
	GLdouble _base;
	GLdouble _top;
	GLdouble _heigh;
	GLdouble _luz;


public:
	Faro(GLdouble base, GLdouble top, GLdouble heigh, GLdouble luz);
	~Faro();

	void dibuja();

};


#endif

