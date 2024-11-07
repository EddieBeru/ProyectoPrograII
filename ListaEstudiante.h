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

	void ingresarLista(string);
	void sacarLista(string);
	bool ingresarEstudiante(Estudiante*);
	bool eliminarEstudiante(Estudiante*);
	bool modificarEstudiante(Estudiante*, Estudiante*);
	Estudiante* getEstudiantePorId(string);
	bool existe(Estudiante*);

	string toString() ;
};

