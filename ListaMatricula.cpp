#include "ListaMatricula.h"

ListaMatricula::ListaMatricula() { primero = NULL; actual = NULL; }
ListaMatricula::~ListaMatricula() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}

bool ListaMatricula::ingresarMatricula(Matricula* Matricula) {
	bool posible = !existe(Matricula);
	if (posible) {
		if (primero == NULL)
			primero = new NodoMatricula(Matricula, NULL);
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL)
				actual = actual->getSiguiente();
			actual->setSiguiente(new NodoMatricula(Matricula, NULL));
		}
	}
	return posible;
}
bool ListaMatricula::eliminarMatricula(Matricula* Matricula) {
	bool posible = existe(Matricula) && primero != NULL;
	if (posible) {
		if (primero->getElemento() == Matricula) {
			NodoMatricula* aEliminar = primero;
			primero = primero->getSiguiente();
			delete aEliminar;
		}
		else {
			actual = primero;
			while (actual->getSiguiente() != NULL && actual->getSiguiente()->getElemento() != Matricula)
				actual = actual->getSiguiente();
			if (actual->getSiguiente() != NULL) {
				NodoMatricula* aEliminar = actual->getSiguiente();
				actual->setSiguiente(actual->getSiguiente()->getSiguiente());
				delete aEliminar;
			}
		}
	}
	return posible;
}
bool ListaMatricula::modificarMatricula(Matricula* original, Matricula* nuevo) {
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
bool ListaMatricula::existe(Matricula* Matricula) {
	bool posible = primero != NULL;
	if (posible) {
		NodoMatricula* tempActual = primero;
		while (tempActual != NULL && tempActual->getElemento() != Matricula)
			tempActual = tempActual->getSiguiente();
		if (tempActual == NULL || tempActual->getElemento() != Matricula)
			posible = false;
	}
	return posible;
}

string ListaMatricula::toString() {
	stringstream s;
	actual = primero;
	while (actual != NULL) {
		s << actual->getElemento()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}
double ListaMatricula::getDescuento(Estudiante* est) {
	int contP = 0;
	int contC = 0;
	actual = primero;
	double descuento = 0;;
	Periodo* per=NULL;
	while (actual != NULL) {
		if (actual->getElemento()->getEstudiante() == est) {
			contC++;
			per = actual->getElemento()->getPeriodo();
			actual = actual->getSiguiente();
			if(actual!=NULL)
				if (actual->getElemento()->getPeriodo()==per)
					contP+=2;
		}
	}
	if (contP >= 2)
		descuento = 0.15;
	if (contC >= 4)
		descuento += 0.25;
	return descuento;
}
double ListaMatricula::getprecioCursos(Estudiante* est) {
	double precioT = 0;
	actual = primero;
	while (actual != NULL) {
		if (actual->getElemento()->getEstudiante() == est)
			precioT+=actual->getElemento()->getCurso()->getPrecio();
		actual = actual->getSiguiente();
	}
	return precioT;
}

string ListaMatricula::factura(Estudiante* est){
	stringstream s;
	actual = primero;
	int contP = 0;
	int contC = 0;
	while (actual != NULL) {
		if (actual->getElemento()->getEstudiante() == est) {
			s << "Curso: "<<actual->getElemento()->getCurso()->getNombre() << endl;
			s << "Precio del Curso: "<<actual->getElemento()->getCurso()->getPrecio() << endl;
			s << "SubTotal: "<<getprecioCursos(est) << endl;
			s << "IVA: ?????????" << endl;
			s << "Descuento: " << getDescuento(est)*100<<"%"<< endl;
			s << "Total: " << getprecioCursos(est) - (getprecioCursos(est) * getDescuento(est)) << endl;
		}
	}
	return s.str();
}