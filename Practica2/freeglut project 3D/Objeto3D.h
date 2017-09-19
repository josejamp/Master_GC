#ifndef Objeto3D_H_
#define Objeto3D_H_

#include "TAfin.h"
#include "Colores.h"


class Objeto3D
{
protected:
	TAfin* mT;
	Colores* color;


public:

	Objeto3D();
	Objeto3D(Colores* color);
	~Objeto3D();

	virtual void dibuja()=0;
	void traslada(PuntoVector3D* punto);
	void escala(GLfloat fX, GLfloat fY, GLfloat fZ);
	void rota(GLfloat alfa, GLfloat fX, GLfloat fY, GLfloat fZ);
	GLfloat* dameMatrizAfin();
	TAfin* getTAfin();

	void setColor(GLfloat r, GLfloat g, GLfloat b);
	Colores* getColor();
};


#endif
