#ifndef COCHE_H_
#define	 COCHE_H_


#include "ObjetoCompuesto.h"
#include "Faro.h"
#include "Rueda.h"
#include "Cubo.h"

class Coche :
	public ObjetoCompuesto
{
public:
	Coche(double largo, double ancho, double altura);
	~Coche();

	void desplazaAdelante();
	void desplazaAtras();
	void tuerceIzqda();
	void tuerceDcha();

	void enciende();
	void apaga();
	
	PuntoVector3D* getPosicion();

protected:

	double _largo;
	double _ancho;
	double _altura;

	double _despl;
	double _angulo;

	Faro* faro1;
	Faro* faro2;

	Rueda** ruedas;

	Cubo* chasis;

};



#endif