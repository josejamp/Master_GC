#ifndef CopaSimple_H_
#define CopaSimple_H_

#include "ObjetoCuadrico.h"
#include "ObjetoCompuesto.h"

class CopaSimple : public ObjetoCompuesto
{

private:
	ObjetoCuadrico* copa;

public:
	CopaSimple(ObjetoCuadrico* obj);
	~CopaSimple();
};

#endif