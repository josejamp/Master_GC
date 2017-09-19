#include "Rueda.h"


Rueda::Rueda(double radio, double profCil){
	_radio = radio;
	_profCil = profCil;

	_cilindro = gluNewQuadric();
	_tapa = gluNewQuadric();
}


Rueda::~Rueda(){

	delete _cilindro;
	delete _tapa;

}


void Rueda::dibuja(){

	double slices = 50;
	double stacks = 50;


	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
		//gluQuadricDrawStyle(_cilindro, GLU_SILHOUETTE);
		glColor3f(0.0f, 0.0f, 0.0f);
		//glTranslated(0, 0, 1); //sin esto no lo pinta de color negro
		//glTranslated(0, 0, -1); //sin esto no lo pinta de color negro
		gluCylinder(_cilindro, _radio, _radio, _profCil, slices, stacks);
	glPopMatrix();

	glPushMatrix();
		//gluQuadricDrawStyle(_tapa, GLU_SILHOUETTE);
		glColor3f(0.0f, 0.0f, 0.0f);
		glTranslated(0, 0, _profCil);
		gluDisk(_tapa, 0, _radio, slices, stacks);
	glPopMatrix();

}


double Rueda::getProfCilindro(){
	return _profCil;
}