#include "Curso.h"

Curso::Curso()
	: nombre(""), id(""), horas(0), precio(0.0), estado(false){}
Curso::Curso(string nombre, string id, int horas, float precio, bool estado)
	: nombre(nombre), id(id), horas(horas), precio(precio), estado(estado){}
Curso::~Curso(){}

string Curso::getNombre() { return nombre; }
string Curso::getId() { return id; }
int Curso::getHoras() { return horas; }
float Curso::getPrecio() { return precio; }
bool Curso::getEstado() { return estado; }

void Curso::setNombre(string nombre) { this->nombre = nombre; }
void Curso::setId(string id) { this->id = id; }
void Curso::setHoras(int horas) { this->horas = horas; }
void Curso::setPrecio(float precio) { this->precio = precio; }
void Curso::setEstado(bool estado) { this->estado = estado; }

string Curso::toString() const { 
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Id: " << id << endl;
	s << "Horas: " << horas << endl;
	s << "Precio: " << precio << endl;
	s << "Estado: " << (estado ? "Si" : "No") << endl;
	return s.str();
}