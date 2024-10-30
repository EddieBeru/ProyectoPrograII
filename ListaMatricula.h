#pragma once
#include "NodoMatricula.h"

class ListaMatricula {
private:
	NodoMatricula* primero;
	NodoMatricula* actual;
public:
	ListaMatricula();
	virtual ~ListaMatricula();

	bool ingresarMatricula(Matricula*);
	bool eliminarMatricula(Matricula*);
	bool modificarMatricula(Matricula*, Matricula*);
	bool existe(Matricula*);
	double getDescuento(Estudiante*);
	double getprecioCursos(Estudiante*);

	string toString();

	string factura(Estudiante*);
};