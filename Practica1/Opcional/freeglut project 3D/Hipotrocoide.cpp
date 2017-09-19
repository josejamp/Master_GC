#define _USE_MATH_DEFINES

#include "Hipotrocoide.h"
#include <math.h>

#include <iostream>

using namespace std;


Hipotrocoide::Hipotrocoide(int nP, int nQ){

	_nP = nP; _nQ = nQ; _a = 7; _b = 4; _c = 2;

	int m = _nP;
	int n = _nQ;
	double r = 0.5;

	//Tam. de los arrays
	numeroVertices = _nP*(_nQ/0.05);
	numeroNormales = _nP*_nQ;
	numeroCaras = numeroNormales;
	//numeroCaras = _nQ;

	//Creacion de los arrays
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	//Creacion del perfil
	PuntoVector3D** perfil = new PuntoVector3D*[m];
	double inc = (2 * M_PI / m);
	for (int i = 0; i < m; i++){
		perfil[i] = new PuntoVector3D(r*cos(((double )i)*inc), r*sin(((double )i)*inc), 0, 1);
	}

	// Vértices de la malla. Multiplicar el perfil por cada una de las m
	int cont = 0;
	for (double t = 0; t < n; t += 0.05){

		PuntoVector3D* T = calculaCPrima(t);
		T->normalizar();

		PuntoVector3D* B = calculaCPrima(t)->productoVectorial(calculaCSegunda(t));
		B->normalizar();

		PuntoVector3D* N = B->productoVectorial(T);

		PuntoVector3D* C = calculaC(t);

		construyeM(N, B, T, C);
			
		
		for (int j = 0; j < m; j++){

			int i = cont*m + j;
			
			double x = _M[0] * perfil[j]->getX() + _M[4] * perfil[j]->getY() + _M[8] * perfil[j]->getZ() + _M[12];
			double y = _M[1] * perfil[j]->getX() + _M[5] * perfil[j]->getY() + _M[9] * perfil[j]->getZ() + _M[13];
			double z = _M[2] * perfil[j]->getX() + _M[6] * perfil[j]->getY() + _M[10] * perfil[j]->getZ() + _M[14];

			PuntoVector3D* p = new PuntoVector3D(x, y, z, 1);

			vertice[i] = p;

		}
		cont++;

	}

	
	//Construccion de las caras
	int indiceCara = 0;
	for (int i = 0; i < n; i++){
		
		for (int j = 0; j < m; j++){

			int indice = i*m + j;

			VerticeNormal** vn = new VerticeNormal*[4];
			vn[0] = new VerticeNormal(indice, indiceCara);
			vn[1] = new VerticeNormal((indice + m) % numeroVertices, indiceCara);
			if (j == m - 1){
				if (i == n - 1){
					vn[2] = new VerticeNormal(((indice + 1 + m) % numeroVertices) - m, indiceCara);
				}
				else{
					vn[2] = new VerticeNormal((indice + 1 + m) - m, indiceCara);
				}
				vn[3] = new VerticeNormal((indice + 1) - m, indiceCara);
			}
			else{
				vn[2] = new VerticeNormal((indice + 1 + m) % numeroVertices, indiceCara);
				vn[3] = new VerticeNormal((indice + 1), indiceCara);
			}

			cara[indiceCara] = new Cara(4, vn);

			PuntoVector3D* v;

			if (j == m - 1){
				PuntoVector3D* v1;
				if (i == n - 1){
					v1 = new PuntoVector3D(vertice[((indice + 1 + m) % numeroVertices) - m]->getX() - vertice[(indice + m) % numeroVertices]->getX(),
						vertice[((indice + 1 + m) % numeroVertices) - m]->getY() - vertice[(indice + m) % numeroVertices]->getY(),
						vertice[((indice + 1 + m) % numeroVertices) - m]->getZ() - vertice[(indice + m) % numeroVertices]->getZ(), 0);
				}
				else{
					v1 = new PuntoVector3D(vertice[(indice + 1 + m) - m]->getX() - vertice[(indice + m) % numeroVertices]->getX(),
						vertice[(indice + 1 + m) - m]->getY() - vertice[(indice + m) % numeroVertices]->getY(),
						vertice[(indice + 1 + m) - m]->getZ() - vertice[(indice + m) % numeroVertices]->getZ(), 0);
				}			
				PuntoVector3D* v2 = new PuntoVector3D(vertice[indice]->getX() - vertice[(indice + m) % numeroVertices]->getX(),
					vertice[indice]->getY() - vertice[(indice + m) % numeroVertices]->getY(),
					vertice[indice]->getZ() - vertice[(indice + m) % numeroVertices]->getZ(), 0);

				v = v2->productoVectorial(v1);
			}
			else{
				PuntoVector3D* v1 = new PuntoVector3D(vertice[(indice + 1 + m) % numeroVertices]->getX() - vertice[(indice + m) % numeroVertices]->getX(),
					vertice[(indice + 1 + m) % numeroVertices]->getY() - vertice[(indice + m) % numeroVertices]->getY(),
					vertice[(indice + 1 + m) % numeroVertices]->getZ() - vertice[(indice + m) % numeroVertices]->getZ(), 0);
				PuntoVector3D* v2 = new PuntoVector3D(vertice[indice]->getX() - vertice[(indice + m) % numeroVertices]->getX(),
					vertice[indice]->getY() - vertice[(indice + m) % numeroVertices]->getY(),
					vertice[indice]->getZ() - vertice[(indice + m) % numeroVertices]->getZ(), 0);

				v = v2->productoVectorial(v1);
			}

			normal[indiceCara] = v;

			indiceCara++;
			

		}
	}

	_modo = GL_POLYGON;

}


Hipotrocoide::~Hipotrocoide(){
	for (int i = 0; i<numeroVertices; i++)
		delete vertice[i];
	delete[] vertice;

	for (int i = 0; i<numeroNormales; i++)
		delete normal[i];
	delete[] normal;

	for (int i = 0; i<numeroCaras; i++)
		delete cara[i];
	delete[] cara;
}


void Hipotrocoide::dibuja(){
	for (int i = 0; i<numeroCaras; i++) {
		glBegin(_modo);
		glColor3f(0.0f, 0.0f, 1.0f);
		for (int j = 0; j<cara[i]->getNumeroVertices(); j++) {
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}


}

void Hipotrocoide::setModo(int modo){
	_modo = modo;
}


PuntoVector3D* Hipotrocoide::calculaC(double t){
	
	
	return new PuntoVector3D(((_a - _b)*cos(t)) + (_c*cos(((_a - _b) / _b)*t)), 
							  0.0f, 
							  ((_a - _b)*sin(t)) - (_c*sin(((_a - _b) / _b)*t)),
							  1);


}

PuntoVector3D* Hipotrocoide::calculaCPrima(double t){
	
	return new PuntoVector3D( ((_b - _a)*sin(t)) - (_c*((_a - _b)/_b)*sin(((_a - _b)/_b)*t)), 
								0.0f, 
								((_a - _b)*cos(t)) - (_c*((_a - _b) / _b)*cos(((_a - _b) / _b)*t)),
								1);


}

PuntoVector3D* Hipotrocoide::calculaCSegunda(double t){
	
	return new PuntoVector3D(((_b - _a)*cos(t)) - (_c*((_a - _b) / _b)*((_a - _b) / _b)*(cos(((_a - _b) / _b)*t))),
							  0.0f,
							  ((_b - _a)*sin(t)) + (_c*((_a - _b) / _b)*((_a - _b) / _b)*(sin(((_a - _b) / _b)*t))),
							  1);
							 
}

void Hipotrocoide::construyeM(PuntoVector3D* N, PuntoVector3D* B, PuntoVector3D* T, PuntoVector3D* C){

	_M[0] = N->getX();
	_M[1] = N->getY();
	_M[2] = N->getZ();
	_M[3] = 0;

	_M[4] = B->getX();
	_M[5] = B->getY();
	_M[6] = B->getZ();
	_M[7] = 0;

	_M[8] = T->getX();
	_M[9] = T->getY();
	_M[10] = T->getZ();
	_M[11] = 0;

	_M[12] = C->getX();
	_M[13] = C->getY();
	_M[14] = C->getZ();
	_M[15] = 1;

}