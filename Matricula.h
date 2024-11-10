#pragma once
#include <sstream>
#include <iostream>
#include <fstream>
#include "ListaPeriodo.h"
#include "ListaCurso.h"
#include "ListaGrupo.h"
#include "ListaEstudiante.h"
using namespace std;

class Matricula {
private:
	//Periodo* periodo;
	//Curso* curso;
	Grupo* grupo;
	Estudiante* estudiante;
public:
	Matricula(Grupo*, Estudiante*);
	virtual ~Matricula();
	Estudiante* getEstudiante();
	//Periodo* getPeriodo();
	//Curso* getCurso();
	Grupo* getgrupo();
	string toString();
	
};