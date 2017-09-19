#ifndef TAfin_H_
#define TAfin_H_

#include "PuntoVector3D.h"


class TAfin
{

private:
	GLfloat* m;

public:
	TAfin();
	~TAfin();

	void traslada(PuntoVector3D* v);
	void postMultiplica(GLfloat* m1);
	void rota(GLfloat angulo, GLfloat x, GLfloat y, GLfloat z);
	void escala(GLfloat x, GLfloat y, GLfloat z);
	void muestraM();
	PuntoVector3D* getPosition();
	GLfloat* dameMatrizModelado();
};

#endif
