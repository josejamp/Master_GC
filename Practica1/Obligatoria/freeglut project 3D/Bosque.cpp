#include "Bosque.h"


Bosque::Bosque()
{
	abeto = new Abeto();
	pino = new Pino();
	roble = new Roble();
	alamo = new Alamo();
}


Bosque::~Bosque()
{
	delete abeto;
	delete alamo;
	delete roble;
	delete pino;
}

void Bosque::dibuja(){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		abeto->dibuja();

		glPushMatrix();
			glTranslated(-4, 0, -4);
			alamo->dibuja();
		glPopMatrix();

		glPushMatrix();
			glTranslated(4, 0, 4);
			pino->dibuja();
		glPopMatrix();

		glPushMatrix();
			glTranslated(4, 0, -4);
			roble->dibuja();
		glPopMatrix();

	glPopMatrix();

}
