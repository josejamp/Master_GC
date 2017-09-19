#include "Roble.h"

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

Roble::Roble(){

	_tronco = new Tronco(1, 0.5, 8);
	_copaEsferica = new CopaEsferica(1.5);

}


Roble::~Roble(){

	delete _tronco;
	delete _copaEsferica;

}


void Roble::dibuja(){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		//glTranslated(4, 0, -4);

		glPushMatrix();
			_tronco->dibuja();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0, 8, 0);
			_copaEsferica->dibuja();
		glPopMatrix();

	glPopMatrix();

}
