#pragma once
#include "Matricula.h"

class NodoMatricula {
private:
	Matricula* elemento;
	NodoMatricula* siguiente;
public:
	NodoMatricula(Matricula*, NodoMatricula*);
	virtual ~NodoMatricula();
	Matricula* getElemento();
	void setElemento(Matricula*);
	NodoMatricula* getSiguiente();
	void setSiguiente(NodoMatricula*);
};