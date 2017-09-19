#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>
using namespace std;

#include "Bosque.h"
#include "Camara.h"
#include "Coche.h"
#include "Farola.h"
#include "Hipotrocoide.h"
#include "BosqueFrondoso.h"
#include "Linterna.h"

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH = 500, HEIGHT = 500;

// Viewing frustum parameters
GLdouble xRight = 10, xLeft = -xRight, yTop = 10, yBot = -yTop, N = 0, F = 1000;

// Camera parameters
GLdouble eyeX = 100.0, eyeY = 100.0, eyeZ = 100.0;
GLdouble lookX = 0.0, lookY = 0.0, lookZ = 0.0;
GLdouble upX = 0, upY = 1, upZ = 0;

// Scene variables
GLfloat angX, angY, angZ;

GLfloat theta = 0.0, phi = 0.0;

bool baldosas = false;

Bosque* bosque;
Camara* camara;
Coche* coche;
Farola* farola;
Hipotrocoide* hipo;
Linterna* linterna;

GLdouble z = 1.00;


void drawScene(){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	// Rotating the scene
	glRotatef(angX, 1.0f, 0.0f, 0.0f);
	glRotatef(angY, 0.0f, 1.0f, 0.0f);
	glRotatef(angZ, 0.0f, 0.0f, 1.0f);

	glLineWidth(1.5f);

	//drawing axes
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(20, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 20, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 20);
	glEnd();


	//GLfloat especular[] = { 3.0, 0.0, 7.0, 1.0 };
	//GLfloat mat_shininess[] = { 3.0 };
	//glShadeModel(GL_SMOOTH);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especular);
	//glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

	
	bosque->dibuja();
	

	glPushMatrix();
		glTranslated(15, 0, 0);
		glColor3f(255.0 / 255, 140.0 / 255, 0.0 / 255);
		glutSolidSphere(6, 500, 500); //Sphere: radius=6, meridians=50, parallels=60
	glPopMatrix();

	glPushMatrix();
		glMultMatrixf(coche->dameMatrizAfin());
		coche->dibuja();
	glPopMatrix();

	glPushMatrix();
		glMultMatrixf(farola->dameMatrizAfin());
		glTranslated(-5, 0, -7);
		farola->dibuja();
	glPopMatrix();

	glPushMatrix();
		glMultMatrixf(linterna->dameMatrizAfin());
		glTranslated(-4, 0, -6);
		linterna->dibuja();
	glPopMatrix();
	

	//hipo->dibuja();

	glPopMatrix();

	
}

void embaldosar(int nCol){
	int cont = 0;
	GLdouble SVAratio = (xRight - xLeft) / (yTop - yBot);
	GLdouble w = (GLdouble)WIDTH / (GLdouble)nCol;
	//La altura de cada puerto se calcula proporcionalmente
	GLdouble h = w / SVAratio;
	for (GLint c = 0; c<nCol; c++){
		GLdouble currentH = 0;
		while ((currentH + h) <= HEIGHT){
			glViewport((GLint)(c*w), (GLint)currentH, (GLint)w, (GLint)h);
			switch (cont) {
			case 0: camara->lateral(); break;
			case 1: camara->frontal(); break;
			case 2: camara->cenital(); break;
			case 3: camara->rincon(); break;
			}
			cont++;
			drawScene(); //dibujar la escena			
			currentH += h;

		}//while
	}//for
}


void desembaldosar(){
	glViewport(0, 0, WIDTH, HEIGHT);
	drawScene();
}


void zoom(GLdouble f){

	
	GLdouble anchoNew = (xRight - xLeft) / f;
	GLdouble altoNew = (yTop - yBot) / f;
	/*
	xLeft = lookX - anchoNew / 2.0;
	xRight = lookX + anchoNew / 2.0;
	yBot = lookY - altoNew / 2.0;
	yTop = lookX + anchoNew / 2.0;
	*/

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	//gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (camara->getProjection())
		glOrtho(xLeft/f, xRight/f, yBot/f, yTop/f, N, F);
	else
		glFrustum(xLeft/f, xRight/f, yBot/f, yTop/f, N, F);


	//glViewport(0, 0, anchoNew, altoNew);

	//cout << camara->getProjection() << endl;
}

void luzFarola(){

	GLenum _luz = GL_LIGHT3;

	GLfloat v[] = { -5.0f, 15.0f, -7.0f, 1.0 };
	glLightfv(_luz, GL_POSITION, v);

	//GLfloat a[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	GLfloat a[] = { 1.0f, 0.0f, 1.0f, 1.0 };
	glLightfv(_luz, GL_AMBIENT, a);
	//GLfloat d[] = { 0.7f, 0.9f, 0.5f, 1.0f };
	GLfloat c[] = { 1.0f, 0.0f, 1.0f, 1.0 };
	glLightfv(_luz, GL_DIFFUSE, c);
	glLightf(_luz, GL_CONSTANT_ATTENUATION, 1);
	glLightf(_luz, GL_LINEAR_ATTENUATION, 0.1);
//	glLightfv(_luz, GL_EMISSION, b); //a

}

void buildSceneObjects() {
	angX = 0.0f;
	angY = 0.0f;
	angZ = 0.0f;

	
	bosque = new Bosque();
	camara = new Camara();
	//camara = new Camara(xRight, xLeft, yTop, yBot, N, F, eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);
	coche = new Coche(5, 5, 5);
	farola = new Farola(0.3, 15);
	hipo = new Hipotrocoide(10, 1000);
	linterna = new Linterna();

}

void initGL() {
	glClearColor(0.6f, 0.7f, 0.8f, 1.0);

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.9f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH); // Shading by default	 

	buildSceneObjects();

	// Light0
	glEnable(GL_LIGHTING);

	GLfloat amb[] = { 0.0, 0.0, 0.0, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);


	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
	glViewport(0, 0, WIDTH, HEIGHT);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glDisable(GL_CULL_FACE);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	zoom(z);

	luzFarola();

	GLfloat d[] = { 0.7f, 0.9f, 0.5f, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
	glLightfv(GL_LIGHT0, GL_SPECULAR, d);
	GLfloat a[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat p[] = { 1.0f, 1.0f, 0.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, p); 

	// Rotating the scene
	/*glRotatef(angX, 1.0f, 0.0f, 0.0f);
	glRotatef(angY, 0.0f, 1.0f, 0.0f);
	glRotatef(angZ, 0.0f, 0.0f, 1.0f);

	glLineWidth(1.5f);
	// Drawing axes
	glBegin( GL_LINES );
	glColor3f(1.0,0.0,0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(20, 0, 0);

	glColor3f(0.0,1.0,0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 20, 0);

	glColor3f(0.0,0.0,1.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 20);
	glEnd();*/

	// Drawing the scene	
	/*
	glColor3f(1.0, 1.0, 1.0);
	glutSolidSphere(6, 50, 60); //Sphere: radius=6, meridians=50, parallels=60
	*/

	//bosque->dibuja();

	if (baldosas) embaldosar(2); //modo baldosas
	else desembaldosar();


	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}



void resize(int newWidth, int newHeight) {
	WIDTH = newWidth;
	HEIGHT = newHeight;
	GLdouble RatioViewPort = (float)WIDTH / (float)HEIGHT;
	glViewport(0, 0, WIDTH, HEIGHT);

	GLdouble SVAWidth = xRight - xLeft;
	GLdouble SVAHeight = yTop - yBot;
	GLdouble SVARatio = SVAWidth / SVAHeight;
	if (SVARatio >= RatioViewPort) {
		GLdouble newHeight = SVAWidth / RatioViewPort;
		GLdouble yMiddle = (yBot + yTop) / 2.0;
		yTop = yMiddle + newHeight / 2.0;
		yBot = yMiddle - newHeight / 2.0;
	}
	else {
		GLdouble newWidth = SVAHeight*RatioViewPort;
		GLdouble xMiddle = (xLeft + xRight) / 2.0;
		xRight = xMiddle + newWidth / 2.0;
		xLeft = xMiddle - newWidth / 2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
	case 27:  /* Escape key */
		//continue_in_main_loop = false; // (**)
		//Freeglut's sentence for stopping glut's main loop (*)
		glutLeaveMainLoop();
		break;
	case 'a': angX = angX + 5; break;
	case 'z': angX = angX - 5; break;
	case 's': angY = angY + 5; break;
	case 'x': angY = angY - 5; break;
	case 'd': angZ = angZ + 5; break;
	case 'c': angZ = angZ - 5; break;
	case '1': camara->giraX(); break;
	case '2': camara->giraY(); break;
	case '3': camara->giraZ(); break;
	case '4': camara->lateral(); break;
	case '5': camara->frontal(); break;
	case '6': camara->cenital(); break;
	case '7': camara->rincon(); break;
	case '8': baldosas = false; break;
	case '9': baldosas = true; break;
	case 'p': {
		camara->projection = !camara->projection;
		camara->setProjection(xLeft,xRight, yBot, yTop, N, F);
	} break;
	case 'q': camara->roll(0.2); break;
	case 'w': camara->yaw(0.2); break;
	case 'e': camara->pitch(0.2); break;
	case 'i': z *= 1.10; break;
	case 'k': z /= 1.10; break;
	case 'n': coche->desplazaAdelante(); break;
	case 'm': coche->desplazaAtras(); break;
	case 't': coche->enciende(); break;
	case 'g': coche->apaga(); break;
	case 'r': farola->enciende(); break;
	case 'f': farola->apaga(); break;
	case 'u': {
		GLfloat amb[] = { 1.0, 1.0, 1.0, 1.0 };
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT,amb);

	} break;
	case 'j': {
		GLfloat amb[] = { 0.0, 0.0, 0.0, 1.0 };
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
	} break;
	case 'y':{
		glEnable(GL_LIGHT0);
	} break;
	case 'h':{
		glDisable(GL_LIGHT0);
	} break;
	case 'o':{
		bosque->cambiaEspecularRoble(-10.0f);
	} break;
	case 'l':{
		bosque->cambiaEspecularRoble(10.0f);
	} break;
	case 'b':{
		camara->avanzaHipotrocoide();
	} break;
	case 'v':{
		theta += 0.01;
		phi += 0.01;
		camara->rotaRespectoObjeto(coche->getPosicion(), theta, phi);
	} break;
	case 'L':{
		linterna->presionaInterruptor();
	} break;
	default:
		need_redisplay = false;
		break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}


void keySpecial(int key, int x, int y){
	bool need_redisplay = true;
	switch (key){
	case GLUT_KEY_UP:
		linterna->mueveLinternaAlante();
		break;
	case GLUT_KEY_DOWN:
		linterna->mueveLinternaAtras();
		break;
	case GLUT_KEY_LEFT:
		linterna->giraIzqda();
		break;
	case GLUT_KEY_RIGHT:
		linterna->giraDcha();
		break;
	default:
		need_redisplay = false;
		break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout << "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	//glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Freeglut 3D-project");

	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutSpecialFunc(keySpecial);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop();

	// We would never reach this point using classic glut
	system("PAUSE");

	return 0;
}


