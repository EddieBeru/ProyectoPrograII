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

	void ingresarLista(string);
	void sacarLista(string);
	bool ingresarGrupo(Grupo*);
	bool eliminarGrupo(Grupo*);
	bool modificarGrupo(Grupo*, Grupo*);
	bool existe(Grupo*);
	Grupo* getGrupoPorNum(int);
	//ListaGrupo* getGruposPorEstudiante(string);

	string toString() ;
};

