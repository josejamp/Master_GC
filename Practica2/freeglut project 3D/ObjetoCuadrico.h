#ifndef ObjetoCuadrico_H_
#define ObjetoCuadrico_H_

#include "Objeto3D.h"


class ObjetoCuadrico: public Objeto3D
{

protected:
	GLUquadricObj* objeto;
public:
	ObjetoCuadrico();
	~ObjetoCuadrico();
};


#endif
