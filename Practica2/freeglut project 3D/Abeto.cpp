#include "Abeto.h"


#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "Cilindro.h"
#include "CopaSimple.h"


#include <GL/freeglut.h>

Abeto::Abeto() : ObjetoCompuesto(2){

	Cilindro* tronco = new Cilindro(1, 0.5, 8, 50, 50);
	CopaSimple* copaCono = new CopaSimple(new Cilindro(1.25, 0, 4, 50, 50));

	tronco->setColor(160.0f / 255, 82.0f / 255, 45.0f / 255);
	introduceObjeto(tronco);
	hijos[numHijos - 1]->rota(-90, 1, 0, 0);


	introduceObjeto(copaCono);
	copaCono->setColor(34.0f / 255, 139.0f / 255, 34.0f / 255, true);
	PuntoVector3D* v = new PuntoVector3D(0, 8, 0, 0);
	hijos[numHijos - 1]->traslada(v);


}


Abeto::~Abeto(){

}