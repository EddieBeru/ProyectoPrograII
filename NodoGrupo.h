#pragma once
#include "Grupo.h"
class NodoGrupo
{
private:
	Grupo* elemento;
	NodoGrupo* siguiente;
public:
	NodoGrupo(Grupo*, NodoGrupo*);
	virtual ~NodoGrupo();
	Grupo* getElemento();
	void setElemento(Grupo*);
	NodoGrupo* getSiguiente();
	void setSiguiente(NodoGrupo*);
};

