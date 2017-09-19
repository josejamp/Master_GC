#include "DiscoParcial.h"


DiscoParcial::DiscoParcial(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint rings, GLdouble startAngle, GLdouble sweepAngle) : ObjetoCuadrico() 
{
	this->innerRadius = innerRadius;
	this->outerRadius = outerRadius;
	this->slices = slices;
	this->rings = rings;
	this->startAngle = startAngle;
	this->sweepAngle = sweepAngle;
}


DiscoParcial::~DiscoParcial()
{
}

void DiscoParcial::dibuja(){

	gluPartialDisk(objeto, innerRadius, outerRadius, slices, rings, startAngle, sweepAngle);

}