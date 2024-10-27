#pragma once
#include "Estudiante.h"
class NodoEstudiante
{
private:
	Estudiante* elemento;
	NodoEstudiante* siguiente;
public:
	NodoEstudiante(Estudiante*, NodoEstudiante*);
	virtual ~NodoEstudiante();
	Estudiante* getElemento();
	void setElemento(Estudiante*);
	NodoEstudiante* getSiguiente();
	void setSiguiente(NodoEstudiante*);
};

