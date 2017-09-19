#ifndef BosqueFrondoso_H_
#define BosqueFrondoso_H_


#include "ObjetoCompuesto.h"
class BosqueFrondoso :
	public ObjetoCompuesto
{

protected:
	GLint _ancho;
	GLint _largo;

	ObjetoCompuesto* dameArbol();
	bool ponArbol();
	void choca(PuntoVector3D* punto, GLfloat alto, GLfloat ancho);

public:
	BosqueFrondoso(GLint ancho, GLint largo);
	~BosqueFrondoso();
};

#endif