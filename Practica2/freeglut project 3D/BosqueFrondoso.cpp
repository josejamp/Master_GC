#include "BosqueFrondoso.h"

#include "Abeto.h"
#include "Pino.h"
#include "Roble.h"
#include "Alamo.h"

#include <ctime>
#include <cstdlib>

#include <iostream>
using namespace std;


BosqueFrondoso::BosqueFrondoso(GLint ancho, GLint largo)
{
	int numArboles = 50;

	srand(time(0));

	_ancho = ancho;
	_largo = largo;

	double desp = 1.0 / ((double)numArboles / ((double)_ancho*(double)_largo));

	//cout << desp << endl;

	for (double i = 0.0; i < _largo; i = i + desp){

		for (double j = 0.0; j < _ancho; j = j + desp){

			if (ponArbol()){
				ObjetoCompuesto* arbol = dameArbol();

				introduceObjeto(arbol);
				PuntoVector3D* v = new PuntoVector3D(j, 0, i, 0);
				hijos[numHijos - 1]->traslada(v);

				//cout << j << endl;
			}
		}

	}


}


BosqueFrondoso::~BosqueFrondoso()
{
}


ObjetoCompuesto* BosqueFrondoso::dameArbol(){

	int randomval = rand() % 4;

	switch (randomval){
	case 0: return new Abeto(); break;
	case 1: return new Alamo(); break;
	case 2: return new Pino(); break;
	case 3: return new Roble(); break;
	}

}


bool BosqueFrondoso::ponArbol(){

	int randomval = rand() % 2;
	
	return randomval;

}

void BosqueFrondoso::choca(PuntoVector3D* punto, GLfloat alto, GLfloat ancho){

	for (int i = 0; i < numHijos; i++){




	}


}