
#ifndef Hipotrocoide_H_
#define Hipotrocoide_H_

#include "Malla.h"

class Hipotrocoide : public Malla {

	protected:
		int _nP;
		int _nQ;
		double _a;
		double _b;
		double _c;
		double _M[16];

		int _modo;

	public:
		Hipotrocoide(int nP, int nQ);
		~Hipotrocoide();
		void dibuja();
		void setModo(int modo);
		PuntoVector3D* getVetice(int pos);
		int getNumVertices();
		PuntoVector3D* calculaC(double t);

	private:
		PuntoVector3D* calculaCPrima(double t);
		PuntoVector3D* calculaCSegunda(double t);
		void Hipotrocoide::construyeM(PuntoVector3D* N, PuntoVector3D* B, PuntoVector3D* T, PuntoVector3D* C);

};

#endif
