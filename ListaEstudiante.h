#pragma once
#include <sstream>
#include <iostream>
#include <fstream>
#include "NodoEstudiante.h"
using namespace std;
class ListaEstudiante {
private:
	NodoEstudiante* primero;
	NodoEstudiante* actual;
public:
	ListaEstudiante();
	virtual ~ListaEstudiante();

	void ingresarLista(const string&);
	void sacarLista(const string&);
	bool ingresarEstudiante(Estudiante*);
	bool eliminarEstudiante(Estudiante*);
	bool modificarEstudiante(Estudiante*, Estudiante*);
	bool existe(Estudiante*);

	string toString() ;
};

