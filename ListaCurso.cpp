#include "ListaCurso.h"
#include <fstream>

ListaCurso::ListaCurso() { primero = NULL; actual = NULL; }
ListaCurso::~ListaCurso() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}
void ListaCurso::ingresarLista(string archivo) {
	ofstream txt(archivo,ios::app);
	actual = this->primero;
	while (actual != NULL) {
		txt << actual->getElemento()->getNombre() << " "
			<< actual->getElemento()->getId() << " "
			<< actual->getElemento()->getHoras() << " "
			<< actual->getElemento()->getPrecio() << " "
			<< actual->getElemento()->getEstado() << endl;
		actual = actual->getSiguiente();
	}
	txt.close();
}
void ListaCurso::sacarLista(string archivo) {
	ifstream txt(archivo);
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
	string nombre, id;
	int horas;
	float precio;
	bool estado;
	txt >> nombre;
	while (!txt.eof()) {

		txt >> id;
		txt >> horas;
		txt >> precio;
		txt >> estado;


		Curso* Cur = new Curso(nombre, id, horas, precio, estado);
		ingresarCurso(Cur);
		txt >> nombre;
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
Curso* ListaCurso::getCursoPorId(string id) {
	actual = primero;
	while (actual != NULL && actual->getElemento()->getId() != id)
		actual = actual->getSiguiente();
	return actual != NULL ? actual->getElemento() : NULL;
}

Curso* ListaCurso::getCursoPos(int pos) {
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

string ListaCurso::toString() {
	stringstream s;
	actual = primero;
	int pos = 0;
	while (actual != NULL) {
		s <<pos <<"- " << actual->getElemento()->toString() << endl;
		actual = actual->getSiguiente();
		s << endl;
		pos++;
	}
	return s.str();
}