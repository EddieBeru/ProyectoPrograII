#include "NodoMatricula.h"

NodoMatricula::NodoMatricula(Matricula* matricula, NodoMatricula* sig)
	:elemento(matricula), siguiente(sig) {}
NodoMatricula::~NodoMatricula() {

}
Matricula* NodoMatricula::getElemento() { return elemento; }
void NodoMatricula::setElemento(Matricula* matricula) {
	elemento = matricula;
	}
NodoMatricula* NodoMatricula::getSiguiente() { return siguiente; }
	void NodoMatricula::setSiguiente(NodoMatricula* sig){
		siguiente = sig;
	}