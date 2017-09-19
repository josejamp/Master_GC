#include "Alamo.h"


#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

Alamo::Alamo(){

	_tronco = new Tronco(1, 0.5, 8);
	_copaEsfericaIzqda = new CopaEsferica(1.75);
	_copaEsfericaDcha = new CopaEsferica(1.5);

}


Alamo::~Alamo(){

	delete _tronco;
	delete _copaEsfericaIzqda;
	delete _copaEsfericaDcha;

}


void Alamo::dibuja(){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		//glTranslated(-4, 0, -4);

		glPushMatrix();
			_tronco->dibuja();
		glPopMatrix();

		glPushMatrix();
			glTranslated(-1, 8, 0);
			_copaEsfericaIzqda->dibuja();
		glPopMatrix();

		glPushMatrix();
			glTranslated(1, 8, 0);
			_copaEsfericaDcha->dibuja();
		glPopMatrix();

	glPopMatrix();

}
