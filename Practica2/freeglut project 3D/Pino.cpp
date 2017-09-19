#include "Pino.h"

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

#include "Cilindro.h"
#include "CopaDoble.h"

Pino::Pino() : ObjetoCompuesto(2){
	Cilindro* tronco = new Cilindro(1, 0.5, 5, 50, 50);

	PuntoVector3D* c2 = new PuntoVector3D(0, 0, 3, 0);
	PuntoVector3D* c1 = new PuntoVector3D(0, 0, 0, 0);
	CopaDoble* copaCono = new CopaDoble(new Cilindro(1.25, 0, 4, 50, 50), new Cilindro(1.25, 0, 4, 50, 50), c1, c2);

	tronco->setColor(160.0f / 255, 82.0f / 255, 45.0f / 255);
	introduceObjeto(tronco);

	hijos[numHijos - 1]->rota(-90, 1, 0, 0);

	copaCono->setColor(34.0f / 255, 139.0f / 255, 34.0f / 255, true);
	introduceObjeto(copaCono);

	PuntoVector3D* v = new PuntoVector3D(0, 5, 0, 0);
	hijos[numHijos - 1]->traslada(v);




}


Pino::~Pino(){


}
