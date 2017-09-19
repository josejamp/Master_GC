#ifndef Farola_H_
#define	Farola_H_


#include "ObjetoCompuesto.h"
class Farola :
	public ObjetoCompuesto
{

protected:
	GLdouble _base;
	GLdouble _heigh;


public:
	Farola(GLdouble base, GLdouble heigh);
	~Farola();

	void enciende();
	void apaga();
};



#endif