#include "LinternaExtremo.h"
#include "Cilindro.h"


LinternaExtremo::LinternaExtremo()
{

	Cilindro* cil = new Cilindro(0.5, 1, 1, 50, 50);

	this->introduceObjeto(cil);
}


LinternaExtremo::~LinternaExtremo()
{
}

void LinternaExtremo::dibuja(){
	ObjetoCompuesto::dibuja();

	//GLdouble angle = atan((_top / 2) / _heigh);
	GLdouble angle = 5.0;
	GLenum _luz = GL_LIGHT5;

	glLightf(_luz, GL_SPOT_CUTOFF, angle);
	glLightf(_luz, GL_SPOT_EXPONENT, 0.0);
	GLfloat dir[] = { 0.0f, 0.0f, 1.0f };
	glLightfv(_luz, GL_SPOT_DIRECTION, dir);
	GLfloat v[] = { 0, 0, 0, 1.0 };
	glLightfv(_luz, GL_POSITION, v);

	GLfloat d[] = { 1.0f, 1.0f, 0.0f, 0.0 };
	glLightfv(_luz, GL_DIFFUSE, d);
	GLfloat a[] = { 0.3f, 0.3f, 0.3f, 1.0 };
	glLightfv(_luz, GL_AMBIENT, a);
}
