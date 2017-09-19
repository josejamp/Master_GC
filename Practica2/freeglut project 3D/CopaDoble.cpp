#include "CopaDoble.h"


CopaDoble::CopaDoble(ObjetoCuadrico* obj1, ObjetoCuadrico* obj2, PuntoVector3D* translateObj1, PuntoVector3D* translateObj2)
{

	copa1 = obj1;
	copa2 = obj2;


	copa1->setColor(color->getR(), color->getG(), color->getB());
	introduceObjeto(copa1);
	hijos[numHijos - 1]->rota(-90, 1, 0, 0);
	hijos[numHijos - 1]->traslada(translateObj1);

	copa2->setColor(color->getR(), color->getG(), color->getB());
	introduceObjeto(copa2);
	hijos[numHijos - 1]->rota(-90, 1, 0, 0);
	hijos[numHijos - 1]->traslada(translateObj2);

}


CopaDoble::~CopaDoble()
{
	delete copa1;
	delete copa2;
}
