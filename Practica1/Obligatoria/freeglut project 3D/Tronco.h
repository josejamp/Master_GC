#ifndef Tronco_H_
#define Tronco_H_

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

class Tronco{

	protected:
		double _radioBase;
		double _radioAltura;
		double _altura;
		GLUquadricObj* _cilindro;


	public:
		Tronco(double radioBase, double radioAltura, double altura);
		~Tronco();
		void dibuja();


};

#endif

