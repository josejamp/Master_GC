#ifndef DiscoParcial_H_
#define DiscoParcial_H_

#include "ObjetoCuadrico.h"
class DiscoParcial: public ObjetoCuadrico
{
protected:
	GLdouble innerRadius;
	GLdouble outerRadius;
	GLint slices;
	GLint rings;
	GLdouble startAngle;
	GLdouble sweepAngle;

public:
	DiscoParcial(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint rings, GLdouble startAngle, GLdouble sweepAngle);
	~DiscoParcial();

	void dibuja();
};

#endif