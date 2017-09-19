#ifndef CopaEsferica_H_
#define CopaEsferica_H_

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

class CopaEsferica{

	protected:
		double _radio;

		GLUquadricObj* _esfera;

	public:
		CopaEsferica(double radio);
		~CopaEsferica();
		void dibuja();


};

#endif

