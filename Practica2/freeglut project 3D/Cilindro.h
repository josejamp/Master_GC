#ifndef Cilindro_H_
#define Cilindro_H_

#include "ObjetoCuadrico.h"

class Cilindro: public ObjetoCuadrico
{

protected:
	GLdouble baseRadius;
	GLdouble topRadius;
	GLdouble heigh; 
	GLint slices;
	GLint stacks;



public:
	Cilindro(GLdouble baseRadius, GLdouble topRadius, GLdouble heigh, GLint slices, GLint stacks);
	~Cilindro();

	void dibuja();
};


#endif