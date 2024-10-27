#pragma once
#include <sstream>
#include <iostream>
#include "NodoGrupo.h"
using namespace std;
class ListaGrupo {
private:
	NodoGrupo* primero;
	NodoGrupo* actual;
public:
	ListaGrupo();
	virtual ~ListaGrupo();

	bool ingresarGrupo(Grupo*);
	bool eliminarGrupo(Grupo*);
	bool modificarGrupo(Grupo*, Grupo*);
	bool existe(Grupo*);

	string toString() ;
};

