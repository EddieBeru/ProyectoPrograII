#include "NodoEstudiante.h"

NodoEstudiante::NodoEstudiante(Estudiante* elemento, NodoEstudiante* siguiente) {
	this->elemento = elemento;
	this->siguiente = siguiente;
}
NodoEstudiante::~NodoEstudiante() {

}
Estudiante* NodoEstudiante::getElemento() { return elemento; }
void NodoEstudiante::setElemento(Estudiante* elemento) { this->elemento = elemento; }
NodoEstudiante* NodoEstudiante::getSiguiente() { return siguiente; }
void NodoEstudiante::setSiguiente(NodoEstudiante* siguiente) { this->siguiente = siguiente; }