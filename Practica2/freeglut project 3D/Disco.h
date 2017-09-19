#ifndef Disco_H_
#define Disco_H_

#include "ObjetoCuadrico.h"

class Disco: public ObjetoCuadrico
{

protected:
	GLdouble innerRadius;
	GLdouble outerRadius;
	GLint slices;
	GLint loops;

public:
	Disco(GLdouble innerRadius, GLdouble outerRadius, GLint slices, GLint loops);
	~Disco();

	void dibuja();
};

#endif