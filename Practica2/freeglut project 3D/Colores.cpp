#include "Colores.h"


Colores::Colores()
{
}

Colores::Colores(GLfloat r, GLfloat g, GLfloat b)
{
	this->_r = r;
	this->_g = g;
	this->_b = b;
}



Colores::~Colores()
{

}

void Colores::setR(GLfloat r){
	_r = r;
}

void Colores::setG(GLfloat g){
	_g = g;
}

void Colores::setB(GLfloat b){
	_b = b;
}

GLfloat Colores::getR(){
	return _r;
}

GLfloat Colores::getG(){
	return _g;
}
GLfloat Colores::getB(){
	return _b;
}