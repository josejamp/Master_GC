#pragma once
#include "ObjetoCompuesto.h"
#include "ObjetoCuadrico.h"
class CopaDoble :
	public ObjetoCompuesto
{
private:
	ObjetoCuadrico* copa1;
	ObjetoCuadrico* copa2;

public:
	CopaDoble(ObjetoCuadrico* obj1, ObjetoCuadrico* obj2, PuntoVector3D* translateObj1, PuntoVector3D* translateObj2);
	~CopaDoble();
};

