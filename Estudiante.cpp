#include "Estudiante.h"

Estudiante::Estudiante(string nom, string ide, string esp, int num, string mail) {
	strcpy_s(nombre, nom.c_str());
	id = ide;
	especialidad = esp;
	numero = num;
	email = mail;
}

Estudiante::~Estudiante(){
	
}

string Estudiante::getNombre() { return nombre; }
string Estudiante::getId() { return id; }
string Estudiante::getEspecialidad() { return especialidad; }
int Estudiante::getNumero() { return numero; }
string Estudiante::getEmail() { return email; }

void Estudiante::setNombre(string nom){
	strcpy_s(nombre, nom.c_str());
}
void Estudiante::setId(string ide){
	id = ide;
}
void Estudiante::setEspecialidad(string esp){
	especialidad = esp;
}
void Estudiante::setNumero(int num){
	numero = num;
}
void Estudiante::setEmail(string mail){
	email = mail;
}

string Estudiante::toString() const { 
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Id: " << id << endl;
	s << "Especialidad: " << especialidad << endl;
	s << "Numero: " << numero << endl;
	s << "Email: " << email << endl;
	return s.str();
}