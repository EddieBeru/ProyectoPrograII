#include "NodoPeriodo.h"

NodoPeriodo::NodoPeriodo(Periodo* elemento, NodoPeriodo* siguiente) {
	this->elemento = elemento;
	this->siguiente = siguiente;
}
NodoPeriodo::~NodoPeriodo() {

}
Periodo* NodoPeriodo::getElemento() { return elemento; }
void NodoPeriodo::setElemento(Periodo* elemento) { this->elemento = elemento; }
NodoPeriodo* NodoPeriodo::getSiguiente() { return siguiente; }
void NodoPeriodo::setSiguiente(NodoPeriodo* siguiente) { this->siguiente = siguiente; }