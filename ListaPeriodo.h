#pragma once
#include <sstream>
#include <iostream>
#include "NodoPeriodo.h"
using namespace std;
class ListaPeriodo {
private:
	NodoPeriodo* primero;
	NodoPeriodo* actual;
public:
	ListaPeriodo();
	virtual ~ListaPeriodo();

	void ingresarLista(string);
	void sacarLista(string);
	bool ingresarPeriodo(Periodo*);
	bool eliminarPeriodo(Periodo*);
	bool modificarPeriodo(Periodo*, Periodo*);
	bool existe(Periodo*);

	string toString() ;
};

