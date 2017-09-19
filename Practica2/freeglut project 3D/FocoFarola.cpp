


#include "FocoFarola.h"
#include "Esfera.h"


FocoFarola::FocoFarola(GLdouble radio)
{

	_radio = radio;

	Esfera* esfera = new Esfera(_radio, 50, 50);


	introduceObjeto(esfera);


}


FocoFarola::~FocoFarola()
{
}

void FocoFarola::dibuja(){

	ObjetoCompuesto::dibuja();


}
