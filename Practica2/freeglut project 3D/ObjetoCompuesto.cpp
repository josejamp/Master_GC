#include "ObjetoCompuesto.h"


#include <iostream>
using namespace std;

ObjetoCompuesto::ObjetoCompuesto() : Objeto3D()
{
	numHijos = 0;
	hijos = new Objeto3D*[1000];
}

ObjetoCompuesto::ObjetoCompuesto(int num) : Objeto3D()
{
	numHijos = 0;
	hijos = new Objeto3D*[num];
}


ObjetoCompuesto::~ObjetoCompuesto()
{
	for (int i = 0; i < numHijos; i++){
		delete hijos[i];
	}
	delete hijos;
}

/*
void ObjetoCompuesto::dibuja(){
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glMultMatrixf(this->mT->m);

	for (int i = 0; i < numHijos; i++){
		cout << "num Hijos" << numHijos << endl;
		cout << "Hijo[" << i << "] = " << hijos[i] << endl;
		hijos[i]->dibuja();
	}

	glPopMatrix();
}
*/

void ObjetoCompuesto::dibuja(){

	for (int i = 0; i < numHijos; i++){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			glMultMatrixf(hijos[i]->dameMatrizAfin());
			glColor3f(hijos[i]->getColor()->getR(), hijos[i]->getColor()->getG(), hijos[i]->getColor()->getB());
			hijos[i]->dibuja();
		glPopMatrix();
	}
}

void ObjetoCompuesto::introduceObjeto(Objeto3D* objeto)	{

	hijos[numHijos] = objeto;

	numHijos++;
}


void ObjetoCompuesto::setColor(GLfloat r, GLfloat g, GLfloat b, bool todos) {
	if (todos){
		for (int i = 0; i < numHijos; i++){
			hijos[i]->setColor(r, g, b);
		}
	}

	color->setR(r);
	color->setG(g);
	color->setB(b);
}