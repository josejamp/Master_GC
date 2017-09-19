#include "Rueda.h"
#include "Cilindro.h"
#include "Disco.h"


Rueda::Rueda(GLdouble base, GLdouble top, GLdouble heigh)
{

	_base = base;
	_top = top;
	_heigh = heigh;

	Cilindro* neumatico = new Cilindro(_base, _top, _heigh, 50, 50);
	Disco* llanta = new Disco(0, _base, 50, 50);

	introduceObjeto(neumatico);

	introduceObjeto(llanta);

	llanta->traslada(new PuntoVector3D(0,0,_heigh,0));

	


}


Rueda::~Rueda()
{
}
