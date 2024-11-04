#pragma once
#include <sstream>
#include <iostream>
#include <fstream>
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
	void ingresarLista(const string& archivo);
	void sacarLista(const string& archivo);
	Profesor* getProfesorEspecifico(int);
	Profesor* getProfesorPorId(string);
	bool eliminarProfesor(Profesor*);
	bool modificarProfesor(Profesor*, Profesor*);
	bool existe(Profesor*);

	string toString() ;
};

