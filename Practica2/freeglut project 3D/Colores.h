#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>

class Colores
{

private:
	GLfloat _r;
	GLfloat _g;
	GLfloat _b;

public:
	Colores();
	Colores(GLfloat r, GLfloat g, GLfloat b);
	~Colores();
	void setR(GLfloat r);
	void setG(GLfloat g);
	void setB(GLfloat b);
	GLfloat getR();
	GLfloat getG();
	GLfloat getB();
};

