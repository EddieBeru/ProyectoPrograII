#include "ListaProfesor.h"
ListaProfesor::ListaProfesor() { primero = NULL; actual = NULL; }
ListaProfesor::~ListaProfesor() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}
void ListaProfesor::ingresarLista(string archivo) {
	ofstream txt(archivo, ios::app);
	actual = this->primero;
	while (actual != NULL) {
		txt << actual->getElemento()->getNombre() << " "
			<< actual->getElemento()->getId() << " "
			<< actual->getElemento()->getNumero() << " "
			<< actual->getElemento()->getEmail() << " "
			<< actual->getElemento()->getGradoAcademico() << endl;
		actual = actual->getSiguiente();
	}
	txt.close();
}
Profesor* ListaProfesor::getProfesorEspecifico(int pos) {
		actual = primero;
		if (pos != 1) {
			for (int i = 1; i < pos; i++) {
				actual = actual->getSiguiente();
			}
			return actual->getElemento();
		}
		else
			return actual->getElemento();
}

Profesor* ListaProfesor::getProfesorPorId(string id) {
	actual = primero;
	while (actual->getSiguiente() != NULL && actual->getElemento()->getId() != id)
		actual = actual->getSiguiente();
	return actual != NULL ? actual->getElemento() : NULL;

}
void ListaProfesor::sacarLista(string archivo) {
	ifstream txt(archivo);
	if (!txt) return;
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
	actual = primero;
	while (!txt.eof()) {
		string nombre, id, email, gradAcad;
		int numero;

		txt>>nombre;
		txt >> id;
		txt >> numero;
		txt>>email;
		txt>>gradAcad;

		
		Profesor* Prof = new Profesor(nombre, id, numero, email, gradAcad);
		if (primero == nullptr) {
			primero = new NodoProfesor(Prof, NULL);
		}
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL) {
				actual = actual->getSiguiente();
			}
			actual->setSiguiente(new NodoProfesor(Prof, NULL));
		}
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
	int pos = 0;
	while (actual != NULL) {
		s <<pos<<"- " << actual->getElemento()->toString() << endl;
		actual = actual->getSiguiente();
		s << endl;
	}
	return s.str();
}