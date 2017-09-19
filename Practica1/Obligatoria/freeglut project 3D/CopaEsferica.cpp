#include "CopaEsferica.h"


CopaEsferica::CopaEsferica(double radio){
	_radio = radio;

	_esfera = gluNewQuadric();
}


CopaEsferica::~CopaEsferica(){

	delete _esfera;

}

void CopaEsferica::dibuja(){

	double slices = 50;
	double stacks = 50;

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		glColor3f(0.0f, 1.0f, 0.0f);
		gluSphere(_esfera, _radio, slices, stacks);
	glPopMatrix();

}
