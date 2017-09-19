#ifndef FocoFarola_H_
#define	FocoFarola_H_


#include "ObjetoCompuesto.h"


class FocoFarola :
	public ObjetoCompuesto
{

protected:
	GLdouble _radio;
public:
	FocoFarola(GLdouble radio);
	~FocoFarola();

	void dibuja();
};


#endif
