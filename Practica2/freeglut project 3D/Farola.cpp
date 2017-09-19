#include "Farola.h"
#include "Cilindro.h"
#include "Esfera.h"
#include "FocoFarola.h"


Farola::Farola(GLdouble base, GLdouble heigh)
{

	_base = base;
	_heigh = heigh;

	

	Cilindro* cilindro = new Cilindro(_base, _base, _heigh, 50, 50);
	
	FocoFarola* foco = new FocoFarola(1.75);

	cilindro->setColor(0.0f, 0.0f, 0.0f);
	introduceObjeto(cilindro);
	hijos[0]->rota(-90, 1, 0, 0);

	foco->setColor(1.0f, 1.0f, 1.0f, true);
	introduceObjeto(foco);
	hijos[1]->traslada(new PuntoVector3D(0, _heigh, 0, 0));
	

}


Farola::~Farola()
{
}


void Farola::enciende(){

	glEnable(GL_LIGHT3);

}



void Farola::apaga(){

	glDisable(GL_LIGHT3);

}