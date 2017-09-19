#ifndef RUEDA_H_
#define	 RUEDA_H_


#include "ObjetoCompuesto.h"
class Rueda :
	public ObjetoCompuesto
{

protected:
	GLdouble _base;
	GLdouble _top; 
	GLdouble _heigh;

public:
	Rueda(GLdouble base, GLdouble top, GLdouble heigh);
	~Rueda();
};


#endif