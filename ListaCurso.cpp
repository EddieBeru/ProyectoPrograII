#include "ListaCurso.h"

ListaCurso::ListaCurso() { primero = NULL; actual = NULL; }
ListaCurso::~ListaCurso() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaCurso::ingresarCurso(Curso* curso){
	bool posible = !existe(curso);
	if (posible) {
		if (primero == NULL)
			primero = new NodoCurso(curso, NULL);
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL)
				actual = actual->getSiguiente();
			actual->setSiguiente(new NodoCurso(curso, NULL));
		}
	}
	return posible;
}
bool ListaCurso::eliminarCurso(Curso* curso){
	bool posible = existe(curso) && primero != NULL;
	if (posible) {
		if (primero->getElemento() == curso) {
			NodoCurso* aEliminar = primero;
			primero = primero->getSiguiente();
			delete aEliminar;
		} else {
			actual = primero;
			while (actual->getSiguiente() != NULL && actual->getSiguiente()->getElemento() != curso)
				actual = actual->getSiguiente();
			if (actual->getSiguiente() != NULL) { 
				NodoCurso* aEliminar = actual->getSiguiente();
				actual->setSiguiente(actual->getSiguiente()->getSiguiente());
				delete aEliminar;
			}
		}
	}
	return posible;
}
bool ListaCurso::modificarCurso(Curso* original, Curso* nuevo){
	bool posible = existe(original) && primero != NULL;
	if (posible) {
		actual = primero;
		while (actual -> getSiguiente() != NULL && actual->getElemento() != original)
			actual = actual->getSiguiente();
		if (actual->getElemento() == original)
			actual->setElemento(nuevo);
	}
	return posible;
}
bool ListaCurso::existe(Curso* curso) {
	bool posible = primero != NULL;
	if (posible) {
		NodoCurso* tempActual = primero;
		while (tempActual != NULL && tempActual->getElemento() != curso)
			tempActual = tempActual->getSiguiente();
		if (tempActual == NULL || tempActual->getElemento() != curso)
			posible = false;
	}
	return posible;
}

string ListaCurso::toString() {
	stringstream s;
	actual = primero;
	while (actual != NULL) {
		s << actual->getElemento()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}