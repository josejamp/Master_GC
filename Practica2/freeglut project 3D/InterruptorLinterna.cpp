#include "InterruptorLinterna.h"
#include "Cubo.h"

InterruptorLinterna::InterruptorLinterna()
{
	Cubo* caja = new Cubo();
	Cubo* deslizador = new Cubo();


	this->introduceObjeto(caja);
	hijos[numHijos - 1]->escala(0.5f/11, 0.5f/11, 0.5f/11);


	this->introduceObjeto(deslizador);
	hijos[numHijos - 1]->traslada(new PuntoVector3D(-0.1f, 0.25f, 0.0f, 0));
	hijos[numHijos - 1]->escala(0.3f / 11, 0.2f / 11, 0.5f / 11);
	


}


InterruptorLinterna::~InterruptorLinterna()
{
}

void InterruptorLinterna::enciende(){

	hijos[1]->traslada(new PuntoVector3D(5, 0, 0, 0));

}

void InterruptorLinterna::apaga(){

	hijos[1]->traslada(new PuntoVector3D(-5, 0, 0, 0));

}

