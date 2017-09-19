#include "Roble.h"

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

#include "Cilindro.h"
#include "CopaSimple.h"
#include "Esfera.h"


#include <GL/freeglut.h>

Roble::Roble() : ObjetoCompuesto(2){

	Cilindro* tronco = new Cilindro(1, 0.5, 8, 50, 50);
	CopaSimple* copaCono = new CopaSimple(new Esfera(1.5, 50, 50));

	tronco->setColor(160.0f / 255, 82.0f / 255, 45.0f / 255);
	introduceObjeto(tronco);
	hijos[numHijos - 1]->rota(-90, 1, 0, 0);

	copaCono->setColor(34.0f / 255, 139.0f / 255, 34.0f / 255, true);
	introduceObjeto(copaCono);
	PuntoVector3D* v = new PuntoVector3D(0, 8, 0, 0);
	hijos[numHijos - 1]->traslada(v);

	_especular = 0;

}


Roble::~Roble(){

}


void Roble::dibuja(){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(hijos[0]->dameMatrizAfin());
		glColor3f(hijos[0]->getColor()->getR(), hijos[0]->getColor()->getG(), hijos[0]->getColor()->getB());
		hijos[0]->dibuja();
	glPopMatrix();

	if (_especular > 34){
		GLfloat especular[] = { (34.0f + _especular) / 255, (139.0f + _especular) / 255, (34.0f + _especular) / 255, 1.0 };
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especular);
	}

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(hijos[1]->dameMatrizAfin());
		glColor3f(hijos[1]->getColor()->getR(), hijos[1]->getColor()->getG(), hijos[1]->getColor()->getB());
		hijos[1]->dibuja();
	glPopMatrix();

	GLfloat especular2[] = { 0.0f, 0.0f, 0.0f, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especular2);

}

void Roble::cambiaEspecular(GLfloat esp){

	_especular += esp;

}