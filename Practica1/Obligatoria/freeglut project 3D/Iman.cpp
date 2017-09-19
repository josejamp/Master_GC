#define _USE_MATH_DEFINES

#include "Iman.h"
#include <math.h>
#include <iostream>

using namespace std;

Iman::Iman(int nQ, int rInt, int rExt, int h) {

	_nQ = nQ; _rInt = rInt; _rExt = rExt; _h = h;

	int m = 4; //número de puntos en el perfil original
	PuntoVector3D** perfil = new PuntoVector3D*[m]; //perfil original en el plano XY

	/* Construir perfil; */
	perfil[0] = new PuntoVector3D(_rInt, 0, 0, 1);
	perfil[1] = new PuntoVector3D(_rInt, _h, 0, 1);
	perfil[2] = new PuntoVector3D(_rInt + _rExt, _h, 0, 1);
	perfil[3] = new PuntoVector3D(_rInt + _rExt, 0, 0, 1);

	int	n = _nQ; //número de rotaciones

	//Tam de los arrays
	//numeroVertices  = n*m;
	//numeroCaras = (n-1)*m; //m en vez de (m-1)  porque necesitamos la cara de abajo
	numeroVertices = n*m + 4 + 4;
	numeroCaras = (n - 1)*m + 5 + 5; //m en vez de (m-1) porque necesitamos la cara de abajo, n-1 porque la revolucion no se cierra
	numeroNormales = numeroCaras; //1 normal por cara

	//Creacion de losarrays
	vertice = new PuntoVector3D*[numeroVertices];
	normal = new PuntoVector3D*[numeroNormales];
	cara = new Cara*[numeroCaras];

	//Colocar el perfil original en la tabla de vertices
	for( int j = 0; j<m; j++)
		vertice[j] = perfil[j]->clonar();

	//Vertice de la malla
	for (int i = 1; i < n; i++){
		double theta = i * 180 / (double)(n-1);
		theta = (theta*M_PI) / 180;
		double c = cos(theta);
		double s = sin(theta);
		//R_y es la matriz de rotación sobre el eje Y
		for (int j = 0; j < m; j++){
			int indice = i*m + j;
			//Transformar el punto j-ésimo del perfil original
			double x = c*perfil[j]->getX() + s*perfil[j]->getZ();
			double z = -s*perfil[j]->getX() + c*perfil[j]->getZ();
			PuntoVector3D* p = new PuntoVector3D(x, perfil[j]->getY(), z, 1);
			vertice[indice] = p;
		}
	}

	//Construccion de las caras
	int indiceCara = 0;
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < m; j++){
			int indice = i*m + j;
				VerticeNormal** vn = new VerticeNormal*[4];
				vn[0] = new VerticeNormal(indice, indiceCara);
				vn[1] = new VerticeNormal((indice + m), indiceCara);
				if (j == m - 1){
					vn[2] = new VerticeNormal((indice + 1 + m)-m, indiceCara);
					vn[3] = new VerticeNormal((indice + 1)-m, indiceCara);
				}
				else{
					vn[2] = new VerticeNormal((indice + 1 + m), indiceCara);
					vn[3] = new VerticeNormal((indice + 1), indiceCara);
				}
				cara[indiceCara] = new Cara(4, vn);

				/*
				PuntoVector3D* v1 = new PuntoVector3D(vertice[vn[2]->getIV()]->getX() - vertice[vn[1]->getIV()]->getX(),
				vertice[vn[2]->getIV()]->getY() - vertice[vn[1]->getIV()]->getY(),
				vertice[vn[2]->getIV()]->getZ() - vertice[vn[1]->getIV()]->getZ(), 0);
				PuntoVector3D* v2 = new PuntoVector3D(vertice[vn[0]->getIV()]->getX() - vertice[vn[1]->getIV()]->getX(),
				vertice[vn[0]->getIV()]->getY() - vertice[vn[1]->getIV()]->getY(),
				vertice[vn[0]->getIV()]->getZ() - vertice[vn[1]->getIV()]->getZ(), 0);
				*/

				PuntoVector3D* v;

				if (j == m - 1){
					PuntoVector3D* v1 = new PuntoVector3D(vertice[(indice + 1 + m) - m]->getX() - vertice[indice + m]->getX(),
						vertice[(indice + 1 + m) - m]->getY() - vertice[indice + m]->getY(),
						vertice[(indice + 1 + m) - m]->getZ() - vertice[indice + m]->getZ(), 0);
					PuntoVector3D* v2 = new PuntoVector3D(vertice[indice]->getX() - vertice[indice + m]->getX(),
						vertice[indice]->getY() - vertice[indice + m]->getY(),
						vertice[indice]->getZ() - vertice[indice + m]->getZ(), 0);

					v = v2->productoVectorial(v1);
				}
				else{
					PuntoVector3D* v1 = new PuntoVector3D(vertice[indice + 1 + m]->getX() - vertice[indice + m]->getX(),
						vertice[indice + 1 + m]->getY() - vertice[indice + m]->getY(),
						vertice[indice + 1 + m]->getZ() - vertice[indice + m]->getZ(), 0);
					PuntoVector3D* v2 = new PuntoVector3D(vertice[indice]->getX() - vertice[indice + m]->getX(),
						vertice[indice]->getY() - vertice[indice + m]->getY(),
						vertice[indice]->getZ() - vertice[indice + m]->getZ(), 0);

					v = v2->productoVectorial(v1);
				}



				normal[indiceCara] = v;


				indiceCara++;
			
		}
	}

	/* COMINENZA LA CONSTRUCCION DE LOS POLOS */

	int largo = 5;

	/* POLO 1*/
	
	// Vértices de abajo
	vertice[n*m] = new PuntoVector3D(_rInt, 0, largo, 1);
	vertice[n*m + 1] = new PuntoVector3D(_rInt + _rExt, 0, largo, 1);
	// Vértices de arriba
	vertice[n*m + 2] = new PuntoVector3D(_rInt, _h, largo, 1);
	vertice[n*m + 3] = new PuntoVector3D(_rInt + _rExt, _h, largo, 1);

	// Normales caras frontal y trasera	 
	normal[(n - 1)*m] = new PuntoVector3D(0.0f, 0.0f, -1.0f, 0);
	// Normales caras lateral izquierda y derecha
	normal[(n - 1)*m + 1] = new PuntoVector3D(1.0f, 0.0f, 0.0f, 0);
	normal[(n - 1)*m + 2] = new PuntoVector3D(-1.0f, 0.0f, 0.0f, 0);
	// Normales caras superior e inferior
	normal[(n - 1)*m + 3] = new PuntoVector3D(0.0f, 1.0f, 0.0f, 0);
	normal[(n - 1)*m + 4] = new PuntoVector3D(0.0f, -1.0f, 0.0f, 0);

	// Caras trasera
	VerticeNormal** aVN = new VerticeNormal*[4];
	aVN[0] = new VerticeNormal(n*m, (n-1)*m);
	aVN[1] = new VerticeNormal(n*m + 1, (n - 1)*m);
	aVN[2] = new VerticeNormal(n*m + 3, (n - 1)*m);
	aVN[3] = new VerticeNormal(n*m + 2, (n - 1)*m);
	cara[(n - 1)*m] = new Cara(4, aVN);

	// Caras lateral izquierda y derecha
	aVN = new VerticeNormal*[4];
	aVN[0] = new VerticeNormal(1, (n - 1)*m + 1);
	aVN[1] = new VerticeNormal(0, (n - 1)*m + 1);
	aVN[2] = new VerticeNormal(n*m, (n - 1)*m + 1);
	aVN[3] = new VerticeNormal(n*m + 2, (n - 1)*m + 1);
	cara[(n - 1)*m + 1] = new Cara(4, aVN);

	aVN = new VerticeNormal*[4];
	aVN[0] = new VerticeNormal(3, (n - 1)*m + 2);
	aVN[1] = new VerticeNormal(2, (n - 1)*m + 2);
	aVN[2] = new VerticeNormal(n*m + 3, (n - 1)*m + 2);
	aVN[3] = new VerticeNormal(n*m + 1, (n - 1)*m + 2);
	cara[(n - 1)*m + 2] = new Cara(4, aVN);

	// Caras superior e inferior
	aVN = new VerticeNormal*[4];
	aVN[0] = new VerticeNormal(n*m + 2, (n - 1)*m + 3);
	aVN[1] = new VerticeNormal(n*m + 3, (n - 1)*m + 3);
	aVN[2] = new VerticeNormal(2, (n - 1)*m + 3);
	aVN[3] = new VerticeNormal(1, (n - 1)*m + 3);
	cara[(n - 1)*m + 3] = new Cara(4, aVN);

	aVN = new VerticeNormal*[4];
	aVN[0] = new VerticeNormal(n*m + 1, (n - 1)*m + 4);
	aVN[1] = new VerticeNormal(n*m, (n - 1)*m + 4);
	aVN[2] = new VerticeNormal(0, (n - 1)*m + 4);
	aVN[3] = new VerticeNormal(3, (n - 1)*m + 4);
	cara[(n - 1)*m + 4] = new Cara(4, aVN);
	

	/* POLO 2*/
	
	//cout << "vertice[n*m-1] = " << "(" << vertice[n*m - 1]->getX() << "," << vertice[n*m - 1]->getY() << "," << vertice[n*m - 1]->getZ() << ")" << endl;
	//cout << "vertice[n*m-2] = " << "(" << vertice[n*m - 2]->getX() << "," << vertice[n*m - 2]->getY() << "," << vertice[n*m - 2]->getZ() << ")" << endl;
	//cout << "vertice[n*m-3] = " << "(" << vertice[n*m - 3]->getX() << "," << vertice[n*m - 3]->getY() << "," << vertice[n*m - 3]->getZ() << ")" << endl;
	//cout << "vertice[n*m-4] = " << "(" << vertice[n*m - 4]->getX() << "," << vertice[n*m - 4]->getY() << "," << vertice[n*m - 4]->getZ() << ")" << endl;

	// Vértices de abajo
	vertice[n*m + 4] = new PuntoVector3D(vertice[n*m - 4]->getX(), 0, vertice[n*m - 4]->getZ()+largo, 1);
	vertice[n*m + 5] = new PuntoVector3D(vertice[n*m - 1]->getX(), 0, vertice[n*m - 1]->getZ()+largo, 1);
	// Vértices de arriba
	vertice[n*m + 6] = new PuntoVector3D(vertice[n*m - 3]->getX(), _h, vertice[n*m - 3]->getZ()+largo, 1);
	vertice[n*m + 7] = new PuntoVector3D(vertice[n*m - 2]->getX(), _h, vertice[n*m - 2]->getZ()+largo, 1);

	// Normales caras frontal y trasera	 
	normal[(n - 1)*m + 5] = new PuntoVector3D(0.0f, 0.0f, -1.0f, 0);
	// Normales caras lateral izquierda y derecha
	normal[(n - 1)*m + 6] = new PuntoVector3D(1.0f, 0.0f, 0.0f, 0);
	normal[(n - 1)*m + 7] = new PuntoVector3D(-1.0f, 0.0f, 0.0f, 0);
	// Normales caras superior e inferior
	normal[(n - 1)*m + 8] = new PuntoVector3D(0.0f, 1.0f, 0.0f, 0);
	normal[(n - 1)*m + 9] = new PuntoVector3D(0.0f, -1.0f, 0.0f, 0);

	// Caras trasera
	aVN = new VerticeNormal*[4];
	aVN[0] = new VerticeNormal(n*m + 4, (n - 1)*m + 5);
	aVN[1] = new VerticeNormal(n*m + 6, (n - 1)*m + 5);
	aVN[2] = new VerticeNormal(n*m + 7, (n - 1)*m + 5);
	aVN[3] = new VerticeNormal(n*m + 5, (n - 1)*m + 5);
	cara[(n - 1)*m + 5] = new Cara(4, aVN);

	// Caras lateral izquierda y derecha
	aVN = new VerticeNormal*[4];
	aVN[0] = new VerticeNormal(n*m + 5, (n - 1)*m + 6);
	aVN[1] = new VerticeNormal(n*m + 7, (n - 1)*m + 6);
	aVN[2] = new VerticeNormal(n*m - 2, (n - 1)*m + 6);
	aVN[3] = new VerticeNormal(n*m - 1, (n - 1)*m + 6);
	cara[(n - 1)*m + 6] = new Cara(4, aVN);

	aVN = new VerticeNormal*[4];
	aVN[0] = new VerticeNormal(n*m + 6, (n - 1)*m + 7);
	aVN[1] = new VerticeNormal(n*m + 4, (n - 1)*m + 7);
	aVN[2] = new VerticeNormal(n*m - 4, (n - 1)*m + 7);
	aVN[3] = new VerticeNormal(n*m - 3, (n - 1)*m + 7);
	cara[(n - 1)*m + 7] = new Cara(4, aVN);

	// Caras superior e inferior
	aVN = new VerticeNormal*[4];
	aVN[0] = new VerticeNormal(n*m + 7, (n - 1)*m + 8);
	aVN[1] = new VerticeNormal(n*m + 6, (n - 1)*m + 8);
	aVN[2] = new VerticeNormal(n*m - 3, (n - 1)*m + 8);
	aVN[3] = new VerticeNormal(n*m - 2, (n - 1)*m + 8);
	cara[(n - 1)*m + 8] = new Cara(4, aVN);

	aVN = new VerticeNormal*[4];
	aVN[0] = new VerticeNormal(n*m + 4, (n - 1)*m + 9);
	aVN[1] = new VerticeNormal(n*m + 5, (n - 1)*m + 9);
	aVN[2] = new VerticeNormal(n*m - 1, (n - 1)*m + 9);
	aVN[3] = new VerticeNormal(n*m - 4, (n - 1)*m + 9);
	cara[(n - 1)*m + 9] = new Cara(4, aVN);
	
}

Iman::~Iman(){
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

void Iman::dibuja(){
	for (int i = 0; i<numeroCaras; i++) {
		//cout << "cara: " << i << endl;
		glBegin(GL_POLYGON);
		if (i < ((_nQ-1)*4)/2)
			glColor3f(0.0f, 0.0f, 1.0f);
		else  if (i < ((_nQ-1) * 4))
			glColor3f(1.0f, 0.0f, 0.0f);
		else
			glColor3f(0.5f, 0.5f, 0.5f);
		for (int j = 0; j<cara[i]->getNumeroVertices(); j++) {
			//cout << "   vertice: " << j << endl;
			int iN = cara[i]->getIndiceNormalK(j);
			int iV = cara[i]->getIndiceVerticeK(j);
			glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
			glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
		}
		glEnd();
	}
}
