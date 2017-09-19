#include "CopaSimple.h"


CopaSimple::CopaSimple(ObjetoCuadrico* obj)
{

	copa = obj;

	copa->setColor(color->getR(), color->getG(), color->getB());
	introduceObjeto(copa);
	hijos[numHijos - 1]->rota(-90, 1, 0, 0);
}


CopaSimple::~CopaSimple()
{
	delete copa;
}
