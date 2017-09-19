#ifndef Esfera_H_
#define Esfera_H_

#include "ObjetoCuadrico.h"
class Esfera: public ObjetoCuadrico
{

protected:
	GLdouble radius;
	GLint slices;
	GLint stacks;


public:
	Esfera(GLdouble radius, GLint slices, GLint stacks);
	~Esfera();

	void dibuja();
};

#endif