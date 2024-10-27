#include "ListaEstudiante.h"

ListaEstudiante::ListaEstudiante() { primero = NULL; actual = NULL; }
ListaEstudiante::~ListaEstudiante() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaEstudiante::ingresarEstudiante(Estudiante* Estudiante) {
	bool posible = !existe(Estudiante);
	if (posible) {
		if (primero == NULL)
			primero = new NodoEstudiante(Estudiante, NULL);
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL)
				actual = actual->getSiguiente();
			actual->setSiguiente(new NodoEstudiante(Estudiante, NULL));
		}
	}
	return posible;
}
bool ListaEstudiante::eliminarEstudiante(Estudiante* Estudiante) {
	bool posible = existe(Estudiante) && primero != NULL;
	if (posible) {
		if (primero->getElemento() == Estudiante) {
			NodoEstudiante* aEliminar = primero;
			primero = primero->getSiguiente();
			delete aEliminar;
		}
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL && actual->getSiguiente()->getElemento() != Estudiante)
				actual = actual->getSiguiente();
			if (actual->getSiguiente() != NULL) {
				NodoEstudiante* aEliminar = actual->getSiguiente();
				actual->setSiguiente(actual->getSiguiente()->getSiguiente());
				delete aEliminar;
			}
		}
	}
	return posible;
}
bool ListaEstudiante::modificarEstudiante(Estudiante* original, Estudiante* nuevo) {
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
bool ListaEstudiante::existe(Estudiante* Estudiante) {
	bool posible = primero != NULL;
	if (posible) {
		NodoEstudiante* tempActual = primero;
		while (tempActual != NULL && tempActual->getElemento() != Estudiante)
			tempActual = tempActual->getSiguiente();
		if (tempActual == NULL || tempActual->getElemento() != Estudiante)
			posible = false;
	}
	return posible;
}

string ListaEstudiante::toString() {
	stringstream s;
	actual = primero;
	while (actual != NULL) {
		s << actual->getElemento()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}