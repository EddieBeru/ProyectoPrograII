#include "Matricula.h"

Matricula::Matricula(Grupo* gru, Estudiante* est)
	:grupo(gru),estudiante(est){}
Matricula::~Matricula(){}

Estudiante* Matricula::getEstudiante() { return estudiante; }
//Periodo* Matricula::getPeriodo() { return periodo; }
Grupo* Matricula::getgrupo() { return grupo; }
string Matricula::toString() {
	stringstream s;
	//s << "Periodo: " << periodo << endl;
	//s << "Curso: " << curso << endl;
	s << "Grupo: " << grupo->toString() << endl;
	s << "Estudiante: " << estudiante << endl;
	return s.str();
}
