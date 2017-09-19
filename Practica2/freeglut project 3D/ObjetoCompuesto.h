#ifndef OBJETOCOMPUESTO_H_
#define OBJETOCOMPUESTO_H_

#include "Objeto3D.h"


class ObjetoCompuesto : public Objeto3D {

protected:
	int numHijos;
	Objeto3D** hijos;


public:
	ObjetoCompuesto();
	ObjetoCompuesto(int num);
	~ObjetoCompuesto();


	void introduceObjeto(Objeto3D* objeto);
	void dibuja();
	void setColor(GLfloat r, GLfloat g, GLfloat b, bool todos);
};

#endif