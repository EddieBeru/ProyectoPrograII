#include "Estudiante.h"

Estudiante::Estudiante(){}
Estudiante::Estudiante(string nom, string id, string esp, int num, string email) 
	: nombre(nom), id(id), especialidad(esp), numero(num), email(email){}
Estudiante::~Estudiante(){}

string Estudiante::getNombre() { return nombre; }
string Estudiante::getId() { return id; }
string Estudiante::getEspecialidad() { return especialidad; }
int Estudiante::getNumero() { return numero; }
string Estudiante::getEmail() { return email; }

void Estudiante::setNombre(string){}
void Estudiante::setId(string){}
void Estudiante::setEspecialidad(string){}
void Estudiante::setNumero(int){}
void Estudiante::setEmail(string){}

string Estudiante::toString() const { return ""; }