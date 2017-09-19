#include "Faro.h"

#include "Cilindro.h"


Faro::Faro(GLdouble base, GLdouble top, GLdouble heigh, GLdouble  luz)
{

	_base = base;
	_top = top;
	_heigh = heigh;
	_luz = luz;

	this->introduceObjeto(new Cilindro(base, top, heigh, 50, 50));
	

}


Faro::~Faro()
{
}

void Faro::dibuja() {

	ObjetoCompuesto::dibuja();

	//GLdouble angle = atan((_top / 2) / _heigh);
	GLdouble angle = 5.0;

	glLightf(_luz, GL_SPOT_CUTOFF, angle);
	glLightf(_luz, GL_SPOT_EXPONENT, 0.0);
	GLfloat dir[] = { 0.0f, 0.0f, 1.0f };
	glLightfv(_luz, GL_SPOT_DIRECTION, dir);
	GLfloat v[] = {0, 0, 0, 1.0 };
	glLightfv(_luz, GL_POSITION, v);

	GLfloat d[] = { 1.0f, 1.0f, 0.0f, 0.0 };
	glLightfv(_luz, GL_DIFFUSE, d);
	GLfloat a[] = { 0.3f, 0.3f, 0.3f, 1.0 };
	glLightfv(_luz, GL_AMBIENT, a);


}

