#ifndef Coche_H_
#define Coche_H_

#include "Cubo.h"
#include "Rueda.h"

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

class Coche{

	protected:
		double _largo;
		double _ancho;
		double _altura;

		Cubo* _carcasa;
		Rueda* _ruedaTrasIzq;
		Rueda* _ruedaTrasDer;
		Rueda* _ruedaDelIzq;
		Rueda* _ruedaDelDer;
		GLUquadricObj* _faroIzq;
		GLUquadricObj* _faroDer;

		double _despl;
		double _angulo;


	public:
		Coche(double largo, double ancho, double altura);
		~Coche();
		void dibuja();
		void desplazaAdelante();
		void desplazaAtras();

};

#endif