#include "Tronco.h"



Tronco::Tronco(double radioBase, double radioAltura, double altura)
{
	_radioBase = radioBase;
	_radioAltura = radioAltura;
	_altura = altura;

	_cilindro = gluNewQuadric();

}


Tronco::~Tronco()
{
	delete _cilindro;
}

void Tronco::dibuja(){

	double slices = 50;
	double stacks = 50;

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		glColor3f( 160.0f / 255, 82.0f / 255, 45.0f / 255);
		glRotated(-90, 1,0,0);
		gluCylinder(_cilindro, _radioBase, _radioAltura, _altura, slices, stacks);
	glPopMatrix();

}
