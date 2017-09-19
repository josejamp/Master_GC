#include "Disco.h"


Disco::Disco(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops) : ObjetoCuadrico()
{
	this->innerRadius = innerRadius;
	this->outerRadius = outerRadius;
	this->slices = slices;
	this->loops = loops;
}


Disco::~Disco()
{
}

void Disco::dibuja(){

	gluDisk(objeto, innerRadius, outerRadius, slices, loops);

}
