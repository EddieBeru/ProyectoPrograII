#pragma once
#include <sstream>
#include <iostream>
#include "NodoProfesor.h"
using namespace std;
class ListaProfesor {
private:
	NodoProfesor* primero;
	NodoProfesor* actual;
public:
	ListaProfesor();
	virtual ~ListaProfesor();

	bool ingresarProfesor(Profesor*);
	bool eliminarProfesor(Profesor*);
	bool modificarProfesor(Profesor*, Profesor*);
	bool existe(Profesor*);

	string toString() ;
};

