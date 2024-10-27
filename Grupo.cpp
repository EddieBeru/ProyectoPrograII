#include "Grupo.h"

Grupo::Grupo(){}
Grupo::Grupo(int, int, int, Horario*){}
Grupo::~Grupo(){}

int Grupo::getNumeroGrupo() { return numeroGrupo; }
int Grupo::getCapacidadAlumnos() { return capacidadAlumnos; }
int Grupo::getCantidadAlumnos() { return cantidadAlumnos; }
Horario* Grupo::getHorario() { return horario; }

void Grupo::setNumeroGrupo(int num) { numeroGrupo = num; }
void Grupo::setCapacidadAlumnos(int cap) { capacidadAlumnos = cap; }
void Grupo::setCantidadAlumnos(int can) { cantidadAlumnos = can; }
void Grupo::setHorario(Horario* hor) { horario = hor; }

string Grupo::toString() const { return ""; }