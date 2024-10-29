#include "Profesor.h"
Profesor::Profesor() 
	:nombre(" "),id(" "),numero(0),email(" "),gradoAcademico(" "){}

Profesor::Profesor(string nom, string ide, int num, string mail, string gradAc)
	:nombre(nom),id(ide),numero(num),email(mail),gradoAcademico(gradAc){}
Profesor::~Profesor(){}

string Profesor::getNombre() { return nombre; }
string Profesor::getId() { return id; }
int Profesor::getNumero() { return numero; }
string Profesor::getEmail() { return email; }
string Profesor::getGradoAcademico() { return gradoAcademico; }

void Profesor::setNombre(string nom) {
	nombre = nom;
}
void Profesor::setId(string ide) {
	id = ide;
}
void Profesor::setNumero(int num) {
	numero = num;
}
void Profesor::setEmail(string mail) {
	email = mail;
}
void Profesor::setGradoAcademico(string gradAcad) {
	gradoAcademico = gradAcad;
}

string Profesor::toString() const {
	stringstream s;
	s << "Nombre: " << nombre << endl;
}