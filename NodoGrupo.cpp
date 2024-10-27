#include "NodoGrupo.h"

NodoGrupo::NodoGrupo(Grupo* elemento, NodoGrupo* siguiente) {
	this->elemento = elemento;
	this->siguiente = siguiente;
}
NodoGrupo::~NodoGrupo() {

}
Grupo* NodoGrupo::getElemento() { return elemento; }
void NodoGrupo::setElemento(Grupo* elemento) { this->elemento = elemento; }
NodoGrupo* NodoGrupo::getSiguiente() { return siguiente; }
void NodoGrupo::setSiguiente(NodoGrupo* siguiente) { this->siguiente = siguiente; }