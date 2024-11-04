#pragma once
#include <sstream>
#include <iostream>
#include "NodoCurso.h"
using namespace std;
class ListaCurso {
private:
	NodoCurso* primero;
	NodoCurso* actual;
public:
	ListaCurso();
	virtual ~ListaCurso();

	bool ingresarCurso(Curso*);
	bool eliminarCurso(Curso*);
	bool modificarCurso(Curso*, Curso*);
	bool existe(Curso*);
	Curso* getCursoPorId(string);

	string toString();
};

