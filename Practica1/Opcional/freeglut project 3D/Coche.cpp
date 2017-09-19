#include "Coche.h"


Coche::Coche(double largo, double ancho, double altura){

	_largo = largo;
	_ancho = ancho;
	_altura = altura;

	_carcasa = new Cubo();
	_ruedaTrasIzq = new Rueda(1, 1);
	_ruedaTrasDer = new Rueda(1, 1);
	_ruedaDelIzq = new Rueda(1, 1);
	_ruedaDelDer = new Rueda(1, 1);
	_faroIzq = gluNewQuadric();
	_faroDer = gluNewQuadric();

	_despl = 0;
	_angulo = 0;

}


Coche::~Coche(){

	delete _carcasa;
	delete _ruedaTrasIzq;
	delete _ruedaTrasDer;
	delete _ruedaDelIzq;
	delete _ruedaDelDer;
	delete _faroIzq;
	delete _faroDer;

}


void Coche::dibuja(){

	double slices = 50;
	double stacks = 50;

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		glTranslated(_despl, 0, 0);

		/* Carcasa del coche */
		glPushMatrix();
			glTranslated(_largo/2, _altura/2, _ancho/2);
			glScaled(_largo/11, _altura/11, _ancho/11);
			_carcasa->dibuja();
		glPopMatrix();

		/* Cuatro ruedas */

		// Rueda trasera derecha
		glPushMatrix();
			glTranslated(0, 0, _ancho);
			glRotated(_angulo, 0, 0, 1);
			_ruedaTrasDer->dibuja();
		glPopMatrix();

		// Rueda trasera izquierda
		glPushMatrix();
			glRotated(-180, 1, 0, 0);
			glRotated(-_angulo, 0, 0, 1);
			_ruedaTrasIzq->dibuja();
		glPopMatrix();

		// Rueda delantera derecha
		glPushMatrix();
			glTranslated(_largo, 0, _ancho);
			glRotated(_angulo, 0, 0, 1);
			_ruedaDelDer->dibuja();
		glPopMatrix();

		// Rueda delantera izquierda
		glPushMatrix();
			glTranslated(_largo, 0, 0);
			glRotated(-180, 1, 0, 0);
			glRotated(-_angulo, 0, 0, 1);
			_ruedaDelIzq->dibuja();
		glPopMatrix();


		/* Faros */
		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glTranslated(_largo, _altura/4, _ancho/3);
			glRotated(90, 0, 1, 0);
			gluCylinder(_faroIzq, 0.5, 0.5, 0.5, slices, stacks);
		glPopMatrix();

		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glTranslated(_largo, _altura/4, 2*_ancho/3);
			glRotated(90, 0, 1, 0);
			gluCylinder(_faroDer, 0.5, 0.5, 0.5, slices, stacks);
		glPopMatrix();

	glPopMatrix();


}


void Coche::desplazaAdelante(){

	_despl += 0.5;
	_angulo -= 10;

}


void Coche::desplazaAtras(){

	_despl -= 0.5;
	_angulo += 10;

}
