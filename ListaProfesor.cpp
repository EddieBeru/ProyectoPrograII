#include "ListaProfesor.h"

ListaProfesor::ListaProfesor() { primero = NULL; actual = NULL; }
ListaProfesor::~ListaProfesor() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaProfesor::ingresarProfesor(Profesor* Profesor) {
	bool posible = !existe(Profesor);
	if (posible) {
		if (primero == NULL)
			primero = new NodoProfesor(Profesor, NULL);
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL)
				actual = actual->getSiguiente();
			actual->setSiguiente(new NodoProfesor(Profesor, NULL));
		}
	}
	return posible;
}
bool ListaProfesor::eliminarProfesor(Profesor* Profesor) {
	bool posible = existe(Profesor) && primero != NULL;
	if (posible) {
		if (primero->getElemento() == Profesor) {
			NodoProfesor* aEliminar = primero;
			primero = primero->getSiguiente();
			delete aEliminar;
		}
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL && actual->getSiguiente()->getElemento() != Profesor)
				actual = actual->getSiguiente();
			if (actual->getSiguiente() != NULL) {
				NodoProfesor* aEliminar = actual->getSiguiente();
				actual->setSiguiente(actual->getSiguiente()->getSiguiente());
				delete aEliminar;
			}
		}
	}
	return posible;
}
bool ListaProfesor::modificarProfesor(Profesor* original, Profesor* nuevo) {
	bool posible = existe(original) && primero != NULL;
	if (posible) {
		actual = primero;
		while (actual->getSiguiente() != NULL && actual->getElemento() != original)
			actual = actual->getSiguiente();
		if (actual->getElemento() == original)
			actual->setElemento(nuevo);
	}
	return posible;
}
bool ListaProfesor::existe(Profesor* Profesor) {
	bool posible = primero != NULL;
	if (posible) {
		NodoProfesor* tempActual = primero;
		while (tempActual != NULL && tempActual->getElemento() != Profesor)
			tempActual = tempActual->getSiguiente();
		if (tempActual == NULL || tempActual->getElemento() != Profesor)
			posible = false;
	}
	return posible;
}

string ListaProfesor::toString() {
	stringstream s;
	actual = primero;
	while (actual != NULL) {
		s << actual->getElemento()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}