#include "Abeto.h"

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

Abeto::Abeto(){

	_tronco = new Tronco(1, 0.5, 8);
	_copaCono = new CopaCono(1.25, 4);

}


Abeto::~Abeto(){

	delete _tronco;
	delete _copaCono;

}


void Abeto::dibuja(){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		_tronco->dibuja();	
	glPopMatrix();

	glPushMatrix();
		glTranslated(0,8,0);
		_copaCono->dibuja();
	glPopMatrix();

}