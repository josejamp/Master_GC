#include "TAfin.h"
#include <iostream>

using namespace std;


TAfin::TAfin()
{
	m = new GLfloat[16];

	for (int i = 0; i < 16; i++){
		m[i] = 0;
	}
	m[0] = 1;
	m[5] = 1;
	m[10] = 1;
	m[15] = 1;
}


TAfin::~TAfin()
{
	delete[] m;
}


void TAfin::traslada(PuntoVector3D* v) {

	glMatrixMode(GL_MODELVIEW); 
	glPushMatrix(); 
	glLoadIdentity(); 
	glTranslatef(v->getX(), v->getY(), v->getZ()); 
	GLfloat m1[16]; 
	//Dejar la matriz actual de modelado-vista en m1 
	//Los 16 datos están enumerados por columnas 
	glGetFloatv(GL_MODELVIEW_MATRIX, m1); 
	glPopMatrix(); 
	postMultiplica(m1);

}

void TAfin::postMultiplica(GLfloat* m1) {
	glMatrixMode(GL_MODELVIEW); 
	glPushMatrix(); 
	//Cargar m como matriz actual de modelado-vista 
	glLoadMatrixf(m); 
	//Post-multiplicar por m1 
	glMultMatrixf(m1); 
	//Dejar el resultado en m 
	glGetFloatv(GL_MODELVIEW_MATRIX, m); 
	glPopMatrix();

}

void TAfin::rota(GLfloat angulo, GLfloat x, GLfloat y, GLfloat z){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRotated(angulo, x, y, z);
	GLfloat m1[16];
	//Dejar la matriz actual de modelado-vista en m1 
	//Los 16 datos están enumerados por columnas 
	glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postMultiplica(m1);

}

void TAfin::escala( GLfloat x, GLfloat y, GLfloat z){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glScaled(x, y, z);
	GLfloat m1[16];
	//Dejar la matriz actual de modelado-vista en m1 
	//Los 16 datos están enumerados por columnas 
	glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();
	postMultiplica(m1);

}

GLfloat* TAfin::dameMatrizModelado() {
	return m;
}

void TAfin::muestraM(){
	for (int i = 0; i < 16; i++){
		cout << "m[" << i << "] = " << m[i] << endl;
	}
	cout << endl;
}

PuntoVector3D* TAfin::getPosition(){

	return new PuntoVector3D(m[12],m[13],m[14],0);

}