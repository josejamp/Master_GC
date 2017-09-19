#include "CopaCono.h"


CopaCono::CopaCono(double radioBase, double altura){
	_radioBase = radioBase;
	_altura = altura;

	_cono = gluNewQuadric();
}


CopaCono::~CopaCono(){

	delete _cono;

}

void CopaCono::dibuja(){

	double slices = 50;
	double stacks = 50;

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		glRotated(-90, 1, 0, 0);
		gluCylinder(_cono, _radioBase, 0, _altura, slices, stacks);
	glPopMatrix();

}
