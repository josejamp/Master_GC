#include "Bosque.h"


Bosque::Bosque()
{
	abeto = new Abeto();
	pino = new Pino();
	roble = new Roble();
	alamo = new Alamo();


	introduceObjeto(alamo);
	PuntoVector3D* v = new PuntoVector3D(-4, 0, -4, 0);
	hijos[numHijos - 1]->traslada(v);

	introduceObjeto(pino);
	v = new PuntoVector3D(4, 0, 8, 0);
	hijos[numHijos - 1]->traslada(v);

	introduceObjeto(roble);
	v = new PuntoVector3D(4, 0, -4, 0);
	hijos[numHijos - 1]->traslada(v);

	introduceObjeto(abeto);
	v = new PuntoVector3D(-8, 0, 0, 0);
	hijos[numHijos - 1]->traslada(v);
}


Bosque::~Bosque()
{
	delete abeto;
	delete alamo;
	delete roble;
	delete pino;
}

void Bosque::cambiaEspecularRoble(GLfloat esp){
	roble->cambiaEspecular(esp);
}