#include "ListaEstudiante.h"

ListaEstudiante::ListaEstudiante() { primero = NULL; actual = NULL; }
ListaEstudiante::~ListaEstudiante() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}
void ListaEstudiante::ingresarLista(string archivo) {
	ofstream txt(archivo);
	actual = this->primero;
	while (actual != NULL) {
		txt << actual->getElemento()->getNombre() << " "
			<< actual->getElemento()->getId() << " "
			<< actual->getElemento()->getEspecialidad() << " "
			<< actual->getElemento()->getNumero() << " "
			<< actual->getElemento()->getEmail()  << endl;
		actual = actual->getSiguiente();
	}
	txt.close();
}
void ListaEstudiante::sacarLista(string archivo) {
	ifstream txt(archivo);
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
	actual = primero;
	string nombre, id, email, especialidad;
	int numero;
	txt >> nombre;
	while (!txt.eof()) {

		txt >> id;
		txt >> especialidad;
		txt >> numero;
		txt >> email;


		Estudiante* Est = new Estudiante(nombre, id, especialidad, numero, email);
		if (primero == NULL) {
			primero = new NodoEstudiante(Est, NULL);
		}
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL) {
				actual = actual->getSiguiente();
			}
			actual->setSiguiente(new NodoEstudiante(Est, NULL));
		}
		txt >> nombre;
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