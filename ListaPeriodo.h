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

	bool ingresarPeriodo(Periodo*);
	bool eliminarPeriodo(Periodo*);
	bool modificarPeriodo(Periodo*, Periodo*);
	bool existe(Periodo*);
	Periodo* getPeriodoPorNum(int);

	string toString() ;
};

