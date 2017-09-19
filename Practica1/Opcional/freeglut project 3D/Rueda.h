#ifndef Rueda_H_
#define Rueda_H_

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

class Rueda{


	protected:
		double _radio;
		double _profCil;

		GLUquadricObj* _cilindro;
		GLUquadricObj* _tapa;

	public:
		Rueda(double radio, double profCil);
		~Rueda();
		void dibuja();
		double getProfCilindro();



};

#endif