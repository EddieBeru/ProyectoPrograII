#include "ListaGrupo.h"

ListaGrupo::ListaGrupo() { primero = NULL; actual = NULL; }
ListaGrupo::~ListaGrupo() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaGrupo::ingresarGrupo(Grupo* Grupo) {
	bool posible = !existe(Grupo);
	if (posible) {
		if (primero == NULL)
			primero = new NodoGrupo(Grupo, NULL);
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL)
				actual = actual->getSiguiente();
			actual->setSiguiente(new NodoGrupo(Grupo, NULL));
		}
	}
	return posible;
}
bool ListaGrupo::eliminarGrupo(Grupo* Grupo) {
	bool posible = existe(Grupo) && primero != NULL;
	if (posible) {
		if (primero->getElemento() == Grupo) {
			NodoGrupo* aEliminar = primero;
			primero = primero->getSiguiente();
			delete aEliminar;
		}
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL && actual->getSiguiente()->getElemento() != Grupo)
				actual = actual->getSiguiente();
			if (actual->getSiguiente() != NULL) {
				NodoGrupo* aEliminar = actual->getSiguiente();
				actual->setSiguiente(actual->getSiguiente()->getSiguiente());
				delete aEliminar;
			}
		}
	}
	return posible;
}
bool ListaGrupo::modificarGrupo(Grupo* original, Grupo* nuevo) {
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
bool ListaGrupo::existe(Grupo* Grupo) {
	bool posible = primero != NULL;
	if (posible) {
		NodoGrupo* tempActual = primero;
		while (tempActual != NULL && tempActual->getElemento() != Grupo)
			tempActual = tempActual->getSiguiente();
		if (tempActual == NULL || tempActual->getElemento() != Grupo)
			posible = false;
	}
	return posible;
}

string ListaGrupo::toString() {
	stringstream s;
	actual = primero;
	while (actual != NULL) {
		s << actual->getElemento()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}