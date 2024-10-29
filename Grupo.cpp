#include "Grupo.h"

Grupo::Grupo()
	:numeroGrupo(0),capacidadAlumnos(0),cantidadAlumnos(0),horario(NULL), curso(NULL), profesor(NULL),periodo(NULL) {}
Grupo::Grupo(int numGr, int capAlum, int cantAlum, Horario* hor, Curso* cur ,Periodo* per )
	:numeroGrupo(numGr),capacidadAlumnos(capAlum),cantidadAlumnos(cantAlum),horario(hor), curso(cur),periodo(per),profesor(NULL) {}
Grupo::~Grupo(){
	if (horario != NULL)
		delete horario;
}

int Grupo::getNumeroGrupo() { return numeroGrupo; }
int Grupo::getCapacidadAlumnos() { return capacidadAlumnos; }
int Grupo::getCantidadAlumnos() { return cantidadAlumnos; }
Horario* Grupo::getHorario() { return horario; }

void Grupo::setNumeroGrupo(int num) { numeroGrupo = num; }
void Grupo::setCapacidadAlumnos(int cap) { capacidadAlumnos = cap; }
void Grupo::setCantidadAlumnos(int can) { cantidadAlumnos = can; }
void Grupo::setHorario(Horario* hor) { horario = hor; }
void Grupo::setCurso(Curso* cur) { curso = cur; }
void Grupo::setProfesor(Profesor* prof) { profesor = prof; }
void Grupo::setPeriodo(Periodo* per) { periodo = per; }

string Grupo::toString() const { 
	stringstream s;
	s << "    Curso: " << curso->getNombre() << endl;
	s << "Numero de Grupo: " << numeroGrupo << endl;
	s << "Capacidad de Alumnos: " << capacidadAlumnos << endl;
	s << "Cantidad de Alumnos: " << cantidadAlumnos << endl;
	s << "Horario: " << horario->toString();
	if (profesor != NULL)
		s << "Profesor: " << profesor->getNombre() << endl;
	else
		s << "Aun no hay profesor asignado" << endl;
	return s.str(); 
}