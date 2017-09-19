#pragma once

#include "Hipotrocoide.h"

class RecorreHipotrocoide
{
public:
	RecorreHipotrocoide(Hipotrocoide* hipo);
	~RecorreHipotrocoide();
	PuntoVector3D* getSiguiente();

protected:
	Hipotrocoide* _hipo;
	float _pos;

private:
	float nuevaPos();

};

