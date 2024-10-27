#pragma once
#include "Periodo.h"
class NodoPeriodo
{
private:
	Periodo* elemento;
	NodoPeriodo* siguiente;
public:
	NodoPeriodo(Periodo*, NodoPeriodo*);
	virtual ~NodoPeriodo();
	Periodo* getElemento();
	void setElemento(Periodo*);
	NodoPeriodo* getSiguiente();
	void setSiguiente(NodoPeriodo*);
};

