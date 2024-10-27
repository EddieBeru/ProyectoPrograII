#pragma once
#include "Profesor.h"
class NodoProfesor
{
private:
	Profesor* elemento;
	NodoProfesor* siguiente;
public:
	NodoProfesor(Profesor*, NodoProfesor*);
	virtual ~NodoProfesor();
	Profesor* getElemento();
	void setElemento(Profesor*);
	NodoProfesor* getSiguiente();
	void setSiguiente(NodoProfesor*);
};

