#pragma once
#include <sstream>
#include <iostream>
#include "NodoEstudiante.h"
using namespace std;
class ListaEstudiante {
private:
	NodoEstudiante* primero;
	NodoEstudiante* actual;
public:
	ListaEstudiante();
	virtual ~ListaEstudiante();

	bool ingresarEstudiante(Estudiante*);
	bool eliminarEstudiante(Estudiante*);
	bool modificarEstudiante(Estudiante*, Estudiante*);
	bool existe(Estudiante*);

	string toString() ;
};

