#ifndef CopaCono_H_
#define CopaCono_H_

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

class CopaCono{

	protected:
		double _radioBase;
		double _altura;

		GLUquadricObj* _cono;

	public:
		CopaCono(double radioBase, double altura);
		~CopaCono();
		void dibuja();


};

#endif