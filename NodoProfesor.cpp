#include "NodoProfesor.h"

NodoProfesor::NodoProfesor(Profesor* elemento, NodoProfesor* siguiente) {
	this->elemento = elemento;
	this->siguiente = siguiente;
}
NodoProfesor::~NodoProfesor() {

}
Profesor* NodoProfesor::getElemento() { return elemento; }
void NodoProfesor::setElemento(Profesor* elemento) { this->elemento = elemento; }
NodoProfesor* NodoProfesor::getSiguiente() { return siguiente; }
void NodoProfesor::setSiguiente(NodoProfesor* siguiente) { this->siguiente = siguiente; }