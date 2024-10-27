#pragma once
#include "Curso.h"
class NodoCurso
{
private:
	Curso* elemento;
	NodoCurso* siguiente;
public:
	NodoCurso(Curso*, NodoCurso*);
	virtual ~NodoCurso();
	Curso* getElemento();
	void setElemento(Curso*);
	NodoCurso* getSiguiente();
	void setSiguiente(NodoCurso*);
};

