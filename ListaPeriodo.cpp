#include "ListaPeriodo.h"

ListaPeriodo::ListaPeriodo() { primero = NULL; actual = NULL; }
ListaPeriodo::~ListaPeriodo() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaPeriodo::ingresarPeriodo(Periodo* Periodo) {
	bool posible = !existe(Periodo);
	if (posible) {
		if (primero == NULL)
			primero = new NodoPeriodo(Periodo, NULL);
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL)
				actual = actual->getSiguiente();
			actual->setSiguiente(new NodoPeriodo(Periodo, NULL));
		}
	}
	return posible;
}
bool ListaPeriodo::eliminarPeriodo(Periodo* Periodo) {
	bool posible = existe(Periodo) && primero != NULL;
	if (posible) {
		if (primero->getElemento() == Periodo) {
			NodoPeriodo* aEliminar = primero;
			primero = primero->getSiguiente();
			delete aEliminar;
		}
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL && actual->getSiguiente()->getElemento() != Periodo)
				actual = actual->getSiguiente();
			if (actual->getSiguiente() != NULL) {
				NodoPeriodo* aEliminar = actual->getSiguiente();
				actual->setSiguiente(actual->getSiguiente()->getSiguiente());
				delete aEliminar;
			}
		}
	}
	return posible;
}
bool ListaPeriodo::modificarPeriodo(Periodo* original, Periodo* nuevo) {
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
bool ListaPeriodo::existe(Periodo* Periodo) {
	bool posible = primero != NULL;
	if (posible) {
		NodoPeriodo* tempActual = primero;
		while (tempActual != NULL && tempActual->getElemento() != Periodo)
			tempActual = tempActual->getSiguiente();
		if (tempActual == NULL || tempActual->getElemento() != Periodo)
			posible = false;
	}
	return posible;
}

string ListaPeriodo::toString() {
	stringstream s;
	actual = primero;
	while (actual != NULL) {
		s << actual->getElemento()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}