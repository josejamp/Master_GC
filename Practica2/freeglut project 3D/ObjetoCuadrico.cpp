#include "ObjetoCuadrico.h"


ObjetoCuadrico::ObjetoCuadrico() : Objeto3D()
{
	objeto = gluNewQuadric();
	//gluQuadricDrawStyle(objeto, GLU_LINE);
}


ObjetoCuadrico::~ObjetoCuadrico()
{
	delete objeto;
}
