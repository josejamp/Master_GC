#include "Linterna.h"
#include "Cilindro.h"
#include "LinternaExtremo.h"
#include "InterruptorLinterna.h"

Linterna::Linterna()
{
	_encendida = false;

	Cilindro* cuerpo = new Cilindro(0.5, 0.5, 3, 50, 50);
	LinternaExtremo* extremo = new LinternaExtremo();
	interruptor = new InterruptorLinterna();

	this->introduceObjeto(cuerpo);
	hijos[numHijos - 1]->setColor(0.5, 0.5, 0.5);

	this->introduceObjeto(extremo);
	hijos[numHijos - 1]->traslada(new PuntoVector3D(0, 0, 3, 0));
	extremo->setColor(0.5, 0.5, 0.5, true);

	this->introduceObjeto(interruptor);
	hijos[numHijos - 1]->traslada(new PuntoVector3D(0, 0.5, 1.5, 0));
	interruptor->setColor(0.5, 0.5, 0.5, true);

	this->rota(90, 0, 1, 0);
}


Linterna::~Linterna()
{
}

void Linterna::presionaInterruptor(){
	if (_encendida){
		glDisable(GL_LIGHT5);
		interruptor->apaga();
		_encendida = false;
	}
	else{
		glEnable(GL_LIGHT5);
		interruptor->enciende();
		_encendida = true;
	}
}

void Linterna::mueveLinternaAlante(){

	this->traslada(new PuntoVector3D(0.5, 0, 0, 0));
}

void Linterna::mueveLinternaAtras(){

	this->traslada(new PuntoVector3D(-0.5, 0, 0, 0));
}

void Linterna::giraIzqda(){

	this->rota(10, 0, 1, 0);
}

void Linterna::giraDcha(){

	this->rota(-10, 0, 1, 0);
}


void Linterna::dibuja(){

	for (int i = 0; i < numHijos-1; i++){
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glMultMatrixf(hijos[i]->dameMatrizAfin());
		glColor3f(hijos[i]->getColor()->getR(), hijos[i]->getColor()->getG(), hijos[i]->getColor()->getB());
		hijos[i]->dibuja();
		glPopMatrix();
	}

	GLfloat especular[] = { (34.0f ) / 255, (139.0f ) / 255, (34.0f ) / 255, 1.0 };
	GLfloat ambient[] = { (34.0f) / 255, (139.0f) / 255, (34.0f) / 255, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, ambient);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(hijos[numHijos - 1]->dameMatrizAfin());
	glColor3f(hijos[numHijos - 1]->getColor()->getR(), hijos[numHijos - 1]->getColor()->getG(), hijos[numHijos - 1]->getColor()->getB());
	hijos[numHijos - 1]->dibuja();
	glPopMatrix();

	GLfloat especular2[] = { 0.0f, 0.0f, 0.0f, 1.0 };
	GLfloat ambient2[] = { 0.0f, 0.0f, 0.0f, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especular2);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, ambient2);

}