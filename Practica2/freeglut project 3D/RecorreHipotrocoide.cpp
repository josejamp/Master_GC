#include "RecorreHipotrocoide.h"
#include <iostream>

using namespace std;

RecorreHipotrocoide::RecorreHipotrocoide(Hipotrocoide* hipo)
{
	_hipo = hipo;
	_pos = 0.0f;
}


RecorreHipotrocoide::~RecorreHipotrocoide()
{
}



float RecorreHipotrocoide::nuevaPos(){

	return _pos + 0.05;

}

PuntoVector3D* RecorreHipotrocoide::getSiguiente(){


	PuntoVector3D* nuevo = new PuntoVector3D(
		_hipo->calculaC(_pos)->getX(),
		_hipo->calculaC(_pos)->getY(),
		_hipo->calculaC(_pos)->getZ(),
		1);

	_pos = nuevaPos();

	return nuevo;
}