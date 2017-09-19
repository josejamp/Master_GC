#include "Objeto3D.h"


Objeto3D::Objeto3D() {
	mT = new TAfin();
	this->color = new Colores();
}


Objeto3D::Objeto3D(Colores* color){
	mT = new TAfin();
	this->color = color;
}

Objeto3D:: ~Objeto3D() {
	delete mT;
}

GLfloat* Objeto3D::dameMatrizAfin() {
	return mT->dameMatrizModelado();
}

//To do (usando las correspondientes operaciones de TAfin)
void Objeto3D::traslada(PuntoVector3D* punto) {
	mT->traslada(punto);
}

void Objeto3D::escala(GLfloat fX, GLfloat fY, GLfloat fZ) {
	mT->escala(fX, fY, fZ);
}

void Objeto3D::rota(GLfloat alfa, GLfloat fX, GLfloat fY, GLfloat fZ) {
	mT->rota(alfa, fX, fY, fZ);
}

void Objeto3D::setColor(GLfloat r, GLfloat g, GLfloat b){
	color->setR(r);
	color->setG(g);
	color->setB(b);
}

Colores* Objeto3D::getColor(){
	return color;
}

TAfin* Objeto3D::getTAfin(){
	return mT;
}