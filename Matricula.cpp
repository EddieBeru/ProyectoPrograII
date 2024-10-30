#include "Matricula.h"

Matricula::Matricula(Periodo* per, Curso* cur, Grupo* gru, Estudiante* est)
	:periodo(per),curso(cur),grupo(gru),estudiante(est){}
Matricula::~Matricula(){}

Estudiante* Matricula::getEstudiante() { return estudiante; }
Periodo* Matricula::getPeriodo() { return periodo; }
Curso* Matricula::getCurso() { return curso; }
Grupo* Matricula::getgrupo() { return grupo; }
string Matricula::toString() {
	stringstream s;
	s << "Periodo: " << periodo << endl;
	s << "Curso: " << curso << endl;
	s << "Grupo: " << grupo << endl;
	s << "Estudiante: " << estudiante << endl;
	return s.str();
}
