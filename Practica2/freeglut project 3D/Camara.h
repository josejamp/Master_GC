
#ifndef CamaraH
#define CamaraH

#include "PuntoVector3D.h"
#include "RecorreHipotrocoide.h"

class Camara {
private:
	PuntoVector3D *eye, *up, *look, *u, *v, *n;
	GLfloat left, right, bottom, top, Near, Far;
	GLdouble fovy, aspect;
	RecorreHipotrocoide* _recHipo;

	void setView();
	void setCameraCoordinateSystem();
	void setModelViewMatrix();

public:
	Camara();
	Camara(GLdouble xRight, GLdouble xLeft, GLdouble yTop, GLdouble yBot, GLdouble N, GLdouble F,
		GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ,
		GLdouble lookX, GLdouble lookY, GLdouble lookZ,
		GLdouble upX, GLdouble upY, GLdouble upZ);

	bool projection;

	bool getProjection();

	void giraX();
	void giraY();
	void giraZ();
	void lateral();
	void frontal();
	void cenital();
	void rincon();
	void setProjection();
	void setProjection(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble Near, GLdouble Far);
	void roll(float ang);
	void pitch(float ang);
	void yaw(float ang);
	void zoom(GLdouble f);

	void avanzaHipotrocoide();

	void rotaRespectoObjeto(PuntoVector3D* coordObjeto, GLfloat theta, GLfloat phi);

};
#endif
