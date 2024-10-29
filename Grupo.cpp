#include "Grupo.h"

Grupo::Grupo()
	:numeroGrupo(0),capacidadAlumnos(0),cantidadAlumnos(0),horario(NULL)/*, curso(NULL)*/ {}
Grupo::Grupo(int numGr, int capAlum, int cantAlum, Horario* hor/*, Curso* cur */ )
	:numeroGrupo(numGr),capacidadAlumnos(capAlum),cantidadAlumnos(cantAlum),horario(hor)/*, curso(cur)*/ {}
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

string Grupo::toString() const { 
	stringstream s;
	s << "Numero de Grupo: " << numeroGrupo << endl;
	s << "Capacidad de Alumnos: " << capacidadAlumnos << endl;
	s << "Cantidad de Alumnos: " << cantidadAlumnos << endl;
	s << "Horario: " << horario->toString() << endl;
	//s << "Curso: " << curso->getNombre() << endl;
	return s.str(); 
}