#include "Esfera.h"


Esfera::Esfera(GLdouble radius, GLint slices, GLint stacks) : ObjetoCuadrico()
{

	this->radius = radius;
	this->slices = slices;
	this->stacks = stacks;
}


Esfera::~Esfera()
{
}

void Esfera::dibuja(){
	gluSphere(objeto, radius, slices, stacks);
}