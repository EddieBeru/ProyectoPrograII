#include "NodoCurso.h"

NodoCurso::NodoCurso(Curso* elemento, NodoCurso* siguiente){
	this->elemento = elemento;
	this->siguiente = siguiente;
}
NodoCurso::~NodoCurso(){
	
}
Curso* NodoCurso::getElemento() { return elemento; }
void NodoCurso::setElemento(Curso* elemento) { this->elemento = elemento; }
NodoCurso* NodoCurso::getSiguiente() { return siguiente; }
void NodoCurso::setSiguiente(NodoCurso* siguiente) { this->siguiente = siguiente; }