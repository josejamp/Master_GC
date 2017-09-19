#include "Pino.h"

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

Pino::Pino(){

	_tronco = new Tronco(1, 0.5, 8);
	_copaConoAbajo = new CopaCono(1.25, 4);
	_copaConoArriba = new CopaCono(1.25, 4);

}


Pino::~Pino(){

	delete _tronco;
	delete _copaConoAbajo;
	delete _copaConoArriba;

}


void Pino::dibuja(){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		//glTranslated(4, 0, 4);

		glPushMatrix();
			_tronco->dibuja();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0, 8, 0);
			_copaConoAbajo->dibuja();
		glPopMatrix();

		glPushMatrix();
			glTranslated(0, 11, 0);
			_copaConoArriba->dibuja();
		glPopMatrix();

	glPopMatrix();

}
