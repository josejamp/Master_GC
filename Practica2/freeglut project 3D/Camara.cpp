#define _USE_MATH_DEFINES

#include <math.h>

#include "Camara.h"
#include "Hipotrocoide.h"
#include <iostream>

using namespace std;


Camara::Camara() {
	eye = new PuntoVector3D(10, 10, 10, 1);
	look = new PuntoVector3D(0, 0, 0, 1);
	up = new PuntoVector3D(0, 1, 0, 0);

	left = -10; right = -left; bottom = -10; top = -bottom;
	Near = 0.1; Far = 1000;
	fovy = 5; aspect = 2.5;

	projection = true;

	setView();
	setProjection();
	setCameraCoordinateSystem();

	_recHipo = new RecorreHipotrocoide( new Hipotrocoide(10, 1000));
}

Camara::Camara(GLdouble xRight, GLdouble xLeft, GLdouble yTop, GLdouble yBot, GLdouble N, GLdouble F,
	GLdouble eyeX, GLdouble eyeY, GLdouble eyeZ,
	GLdouble lookX, GLdouble lookY, GLdouble lookZ,
	GLdouble upX, GLdouble upY, GLdouble upZ)
{

	eye = new PuntoVector3D(eyeX, eyeY, eyeZ, 1);
	look = new PuntoVector3D(lookX, lookY, lookZ, 1);
	up = new PuntoVector3D(upX, upY, upZ, 0);

	left = xLeft; right = xRight; bottom = yBot; top = yTop;
	Near = N; Far = F;
	fovy = 5; aspect = 2.5;

	projection = true;

	setView();
	setProjection();
	setCameraCoordinateSystem();

	_recHipo = new RecorreHipotrocoide(new Hipotrocoide(10, 1000));
}

void Camara::setView() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye->getX(), eye->getY(), eye->getZ(), look->getX(), look->getY(), look->getZ(), up->getX(), up->getY(), up->getZ());
}

void Camara::setCameraCoordinateSystem() {
	//Obtiene el valor de los vectores u, v, n  
	n = new PuntoVector3D(eye->getX() - look->getX(), eye->getY() - look->getY(), eye->getZ() - look->getZ(), 0);
	n->normalizar();

	u = up->productoVectorial(n);
	u->normalizar();

	v = n->productoVectorial(u);

	setModelViewMatrix();

}


void Camara::setProjection() {
	//Define la matriz de proyección con el comando 
	//glOrtho() o glFrustum()/gluPerspective()	 
	if (projection){
		//setView();
		//setCameraCoordinateSystem();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(left, right, bottom, top, Near, Far);
	}
	else{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(left, right, bottom, top, Near, Far);
		//gluPerspective(fovy, aspect, Near, Far);
	}

}

void Camara::setProjection(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble Near, GLdouble Far) {
	//Define la matriz de proyección con el comando 
	//glOrtho() o glFrustum()/gluPerspective()	 
	if (projection){
		//setView();
		//setCameraCoordinateSystem();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(left, right, bottom, top, Near, Far);
	}
	else{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glFrustum(left, right, bottom, top, Near, Far);
		//gluPerspective(fovy, aspect, Near, Far);
	}

}

void Camara::setModelViewMatrix() {
	glMatrixMode(GL_MODELVIEW);
	GLfloat m[16];
	m[0] = u->getX(); m[4] = u->getY(); m[8] = u->getZ(); m[12] = -eye->productoEscalar(u);
	m[1] = v->getX(); m[5] = v->getY(); m[9] = v->getZ(); m[13] = -eye->productoEscalar(v);
	m[2] = n->getX(); m[6] = n->getY(); m[10] = n->getZ(); m[14] = -eye->productoEscalar(n);
	m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1;
	glLoadMatrixf(m);
}

void Camara::giraX() {
	//Gira la cámara alrededor del eje X sobre un plano perpendicular a este eje	
	GLfloat d = sqrt(pow(eye->getY() - look->getY(), 2) + pow(eye->getZ() - look->getZ(), 2));
	float theta = atan2(eye->getZ(), eye->getY());
	float theta_p = theta + 0.1;

	eye = new PuntoVector3D(eye->getX(), d*cos(theta_p), d*sin(theta_p), 1);

	setView();
	setCameraCoordinateSystem();
}


void Camara::giraY() {
	//Gira la cámara alrededor del eje Y sobre un plano perpendicular a este eje
	GLfloat d = sqrt(pow(eye->getX() - look->getX(), 2) + pow(eye->getZ() - look->getZ(), 2));
	float theta = atan2(eye->getX(), eye->getZ());
	float theta_p = theta + 0.1;

	eye = new PuntoVector3D(d*sin(theta_p), eye->getY(), d*cos(theta_p), 1);


	setView();
	setCameraCoordinateSystem();
}

void Camara::giraZ() {
	//Gira la cámara alrededor del eje Z sobre un plano perpendicular a este eje
	GLfloat d = sqrt(pow(eye->getX() - look->getX(), 2) + pow(eye->getY() - look->getY(), 2));
	float theta = atan2(eye->getX(), eye->getY());
	float theta_p = theta + 0.1;

	eye = new PuntoVector3D(d*sin(theta_p), d*cos(theta_p), eye->getZ(), 1);


	setView();
	setCameraCoordinateSystem();
}

void Camara::lateral() {
	//Coloca la cámara de forma que se muestra una visión lateral 
	//de la escena (desde el eje X) 

	eye = new PuntoVector3D(10, 0, 0, 1);
	up = new PuntoVector3D(0, 1, 0, 1);


	setView();
	setCameraCoordinateSystem();
}

void Camara::frontal() {
	//Coloca la cámara de forma que se muestra una visión frontal 
	//de la escena (desde el eje Z)  

	eye = new PuntoVector3D(0, 0, 10, 1);
	up = new PuntoVector3D(0, 1, 0, 1);

	setView();
	setCameraCoordinateSystem();
}

void Camara::cenital() {
	//Coloca la cámara de forma que se muestra una visión cenital 
	//de la escena (desde el eje Y) 

	eye = new PuntoVector3D(0, 10, 0, 1);
	up = new PuntoVector3D(1, 0, 0, 1);

	setView();
	setCameraCoordinateSystem();
}


void Camara::rincon() {
	//Coloca la cámara de forma que se muestra
	//la escena en un rincón

	eye = new PuntoVector3D(10, 10, 10, 1);
	up = new PuntoVector3D(0, 1, 0, 1);

	setView();
	setCameraCoordinateSystem();
}

void Camara::pitch(float ang) {
	//Rota la cámara tal como se explica en las transparencias

	ang = (ang*M_PI) / 180;

	PuntoVector3D *v_p = new PuntoVector3D(cos(ang)*v->getX() + sin(ang)*n->getX(),
		cos(ang)*v->getY() + sin(ang)*n->getY(),
		cos(ang)*v->getZ() + sin(ang)*n->getZ(),
		1);

	PuntoVector3D *n_p = new PuntoVector3D(-sin(ang)*v->getX() + cos(ang)*n->getX(),
		-sin(ang)*v->getY() + cos(ang)*n->getY(),
		-sin(ang)*v->getZ() + cos(ang)*n->getZ(),
		1);
	v = v_p;
	n = n_p;

	v->normalizar();
	n->normalizar();


	setModelViewMatrix();
}

void Camara::yaw(float ang) {

	ang = (ang*M_PI) / 180;

	PuntoVector3D *u_p = new PuntoVector3D(cos(ang)*u->getX() - sin(ang)*n->getX(),
		cos(ang)*u->getY() - sin(ang)*n->getY(),
		cos(ang)*u->getZ() - sin(ang)*n->getZ(),
		1);

	PuntoVector3D *n_p = new PuntoVector3D(sin(ang)*u->getX() + cos(ang)*n->getX(),
		sin(ang)*u->getY() + cos(ang)*n->getY(),
		sin(ang)*u->getZ() + cos(ang)*n->getZ(),
		1);
	u = u_p;
	n = n_p;

	u->normalizar();
	n->normalizar();


	setModelViewMatrix();
}

void Camara::roll(float ang) {

	ang = (ang*M_PI) / 180;

	PuntoVector3D *u_p = new PuntoVector3D(cos(ang)*u->getX() + sin(ang)*v->getX(),
		cos(ang)*u->getY() + sin(ang)*v->getY(),
		cos(ang)*u->getZ() + sin(ang)*v->getZ(),
		1);

	PuntoVector3D *v_p = new PuntoVector3D(-sin(ang)*u->getX() + cos(ang)*v->getX(),
		-sin(ang)*u->getY() + cos(ang)*v->getY(),
		-sin(ang)*u->getZ() + cos(ang)*v->getZ(),
		1);
	u = u_p;
	v = v_p;

	u->normalizar();
	v->normalizar();


	setModelViewMatrix();
}


void Camara::zoom(GLdouble f){

	GLdouble anchoNew = (right - left) / f;
	GLdouble altoNew = (top - bottom) / f;

	left = look->getX() - anchoNew / 2.0;
	right = look->getX() + anchoNew / 2.0;
	bottom = look->getY() - altoNew / 2.0;
	top = look->getX() + anchoNew / 2.0;


	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	//gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, Near, Far);

	glViewport(0, 0, anchoNew, altoNew);


}


bool Camara::getProjection(){
	return projection;
}


void Camara::avanzaHipotrocoide(){

	//up = new PuntoVector3D(0, 1, 0, 1);
	eye = _recHipo->getSiguiente();
	look = _recHipo->getSiguiente();

	cout << "Eye = " << eye->getX() << "," << eye->getY() << "," << eye->getZ() << endl;
	cout << "Look = " << look->getX() << "," << look->getY() << "," << look->getZ() << endl;

	setView();
	setCameraCoordinateSystem();
}

void Camara::rotaRespectoObjeto(PuntoVector3D* coordObjeto, GLfloat theta, GLfloat phi){

	GLfloat radio = 5;

	eye = new PuntoVector3D(coordObjeto->getX() + radio*sin(theta), eye->getY(), coordObjeto->getZ() + radio*cos(phi), 1);
	look = new PuntoVector3D(coordObjeto->getX(), look->getY(), coordObjeto->getZ(), 1);

	setView();
	setCameraCoordinateSystem();
}
