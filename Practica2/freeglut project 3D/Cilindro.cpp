#include "Cilindro.h"


Cilindro::Cilindro(GLdouble baseRadius, GLdouble topRadius, GLdouble heigh, GLint slices, GLint stacks) : ObjetoCuadrico()
{
	this->baseRadius = baseRadius;
	this->topRadius = topRadius;
	this->heigh = heigh;
	this->slices = slices;
	this->stacks = stacks;
}


Cilindro::~Cilindro()
{
}


void Cilindro::dibuja(){

	gluCylinder(objeto, baseRadius, topRadius, heigh, slices, stacks);


}