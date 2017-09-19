#include "Coche.h"
#include <iostream>

using namespace std;



Coche::Coche(double largo, double ancho, double altura)
{
	
	_largo = largo;
	_ancho = ancho;
	_altura = altura;

	_despl = 0;
	_angulo = 0;


	//Se añaden 7 elementos al objeto compuesto Coche
	ruedas = new Rueda*[4];
	for (int i = 0; i < 4; i++){
		ruedas[i] = new Rueda(1, 1, 1);
		ruedas[i]->setColor(0.0f, 0.0f, 0.0f, true);
		this->introduceObjeto(ruedas[i]);
	}

	faro1 = new Faro(0.25, 0.5, 0.5, GL_LIGHT1);
	faro2 = new Faro(0.25, 0.5, 0.5, GL_LIGHT2);
	faro1->setColor(0.0f, 1.0f, 0.0f, true);
	faro2->setColor(0.0f, 1.0f, 0.0f, true);
	this->introduceObjeto(faro1);
	this->introduceObjeto(faro2);

	chasis = new Cubo();
	chasis->setColor(1.0f, 0.0f, 0.0f);
	//chasis->setColor(1.0f, 0.0f, 1.0f);
	this->introduceObjeto(chasis);


	//Se sitúan los 7 elementos dentro del coche

	// Rueda trasera derecha
	hijos[0]->traslada(new PuntoVector3D(0, 0, _ancho, 0));
	//hijos[0]->rota(_angulo, 1, 0, 0);
	//hijos[0]->dibuja();
	// Rueda trasera izquierda
	hijos[1]->traslada(new PuntoVector3D(0, 0, 0, 0));
	hijos[1]->rota(-180, 1, 0, 0);
	//hijos[1]->rota(-_angulo, 0, 0, 1);
	//hijos[1]->dibuja();
	// Rueda delantera derecha
	hijos[2]->traslada(new PuntoVector3D(_largo, 0, _ancho, 0));
	//hijos[2]->rota(_angulo, 0, 0, 1);
	//hijos[2]->dibuja();
	// Rueda delantera izquierda
	hijos[3]->traslada(new PuntoVector3D(_largo, 0, 0, 0));
	hijos[3]->rota(-180, 1, 0, 0);
	//hijos[3]->rota(-_angulo, 0, 0, 1);
	//hijos[3]->dibuja();
	
	//Faros
	hijos[4]->traslada(new PuntoVector3D(_largo, _altura / 4, _ancho / 3, 0));
	hijos[4]->rota(90, 0, 1, 0);

	hijos[5]->traslada(new PuntoVector3D(_largo, _altura / 4, 2*_ancho / 3, 0));
	hijos[5]->rota(90, 0, 1, 0);

	//Chasis
	hijos[6]->traslada(new PuntoVector3D(_largo / 2, _altura / 2, _ancho / 2, 0));
	hijos[6]->escala(_largo / 11, _altura / 11, _ancho / 11);




	
}



Coche::~Coche()
{
}


void Coche::desplazaAdelante(){

	_despl = 0.5;
	_angulo = -10;

	this->traslada(new PuntoVector3D(_despl, 0, 0, 0));

	mT->muestraM();

	cout << "Pos = (" << mT->getPosition()->getX() << ", " << mT->getPosition()->getY() << ", " << mT->getPosition()->getZ() << endl;

	hijos[0]->rota(_angulo, 0, 0, 1);
	hijos[1]->rota(-_angulo, 0, 0, 1);
	hijos[2]->rota(_angulo, 0, 0, 1);
	hijos[3]->rota(-_angulo, 0, 0, 1);

}


void Coche::desplazaAtras(){

	_despl = -0.5;
	_angulo = 10;

	this->traslada(new PuntoVector3D(_despl, 0, 0, 0));

	mT->muestraM();

	cout << "Pos = (" << mT->getPosition()->getX() << ", " << mT->getPosition()->getY() << ", " << mT->getPosition()->getZ() << endl;

	hijos[0]->rota(_angulo, 0, 0, 1);
	hijos[1]->rota(-_angulo, 0, 0, 1);
	hijos[2]->rota(_angulo, 0, 0, 1);
	hijos[3]->rota(-_angulo, 0, 0, 1);

}


void Coche::tuerceIzqda(){

	_angulo = 10;

	this->rota(_angulo, 0, 1, 0);

	mT->muestraM();

	cout << "Pos = (" << mT->getPosition()->getX() << ", " << mT->getPosition()->getY() << ", " << mT->getPosition()->getZ() << endl;
}


void Coche::tuerceDcha(){

	_angulo = -10;

	this->rota(_angulo, 0, 1, 0);

	mT->muestraM();

	cout << "Pos = (" << mT->getPosition()->getX() << ", " << mT->getPosition()->getY() << ", " << mT->getPosition()->getZ() << endl;
}


void Coche::enciende(){
	
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	
	
}



void Coche::apaga(){

	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT2);

}

PuntoVector3D* Coche::getPosicion(){
	return mT->getPosition();
}