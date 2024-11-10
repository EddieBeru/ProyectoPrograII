#include "ListaGrupo.h"
#include <fstream>

ListaGrupo::ListaGrupo() { primero = NULL; actual = NULL; }
ListaGrupo::~ListaGrupo() {
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
}
void ListaGrupo::ingresarLista(string archivo) {
	ofstream txt(archivo, ios::app);
	actual = this->primero;
	while (actual != NULL) {
		txt << actual->getElemento()->getNumeroGrupo() << " "
			<< actual->getElemento()->getCapacidadAlumnos() << " "
			<< actual->getElemento()->getCantidadAlumnos() << " "
			<< actual->getElemento()->getHorario()->getHoraInicio() << " "
			<< actual->getElemento()->getHorario()->getHoraFinal() << " "
			<< actual->getElemento()->getHorario()->getDiasSemana() << " "
			<< actual->getElemento()->getCurso()->getNombre() << " "
			<< actual->getElemento()->getCurso()->getId() << " "
			<< actual->getElemento()->getCurso()->getHoras() << " "
			<< actual->getElemento()->getCurso()->getPrecio() << " "
			<< actual->getElemento()->getCurso()->getEstado() << " "
			<< actual->getElemento()->getPeriodo()->getPeriodo() << " ";
		if (actual->getElemento()->getProfesor() == NULL)
			txt << NULL << endl;
		else {
			txt << actual->getElemento()->getProfesor()->getNombre() << " ";
			txt << actual->getElemento()->getProfesor()->getId() << " ";
			txt << actual->getElemento()->getProfesor()->getNumero() << " ";
			txt << actual->getElemento()->getProfesor()->getEmail() << " ";
			txt << actual->getElemento()->getProfesor()->getGradoAcademico() << endl;
		}
		actual = actual->getSiguiente();
	}
	txt.close();
}
void ListaGrupo::sacarLista(string archivo) {
	ifstream txt(archivo);
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
	}
	int numGrupo, capAlumn, cantAlumn;

	int horaInicio, horaFinal, diasSemana;
	string nombreCurso, idCurso;
	int horasCurso;
	float precioCurso;
	bool estadoCurso;
	string nombreProf, idProf, emailProf, gradoAcademicoProf;
	int numeroProf;
	int periodoNombre;
	string profe;

	txt >> numGrupo;

	while (!txt.eof()) {
		txt >> capAlumn;
		txt >> cantAlumn;

		
		txt >> horaInicio;
		txt >> horaFinal;
		txt >> diasSemana;
		Horario* hor = new Horario(horaInicio, horaFinal, diasSemana);

		txt >> nombreCurso;
		txt >> idCurso;
		txt >> horasCurso;
		txt >> precioCurso;
		txt >> estadoCurso;
		Curso* cur = new Curso(nombreCurso, idCurso, horasCurso, precioCurso, estadoCurso);

		
		txt >> periodoNombre;

		Periodo* per = new Periodo(periodoNombre);

		
		txt >> profe;
		Profesor* prof = NULL;

		if (profe != "0") {
			nombreProf = profe; 
			txt >> idProf;
			txt >> numeroProf;
			txt >> emailProf;
			txt >> gradoAcademicoProf;
			prof = new Profesor(nombreProf, idProf, numeroProf, emailProf, gradoAcademicoProf);
		}

		
		Grupo* grupo = new Grupo(numGrupo, capAlumn, cantAlumn, hor, cur, per);
		grupo->setProfesor(prof);

		ingresarGrupo(grupo);
		txt >> numGrupo;
	}

	txt.close();
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
ListaGrupo* ListaGrupo::getGruposPorCurso(string curId) {
	ListaGrupo* grupos = new ListaGrupo();
	actual = primero;
	if (actual != NULL) {
		while (actual->getSiguiente() != NULL) {
			if (actual->getElemento()->getCurso()->getId() == curId) {
				grupos->ingresarGrupo(actual->getElemento());
			}
			actual = actual->getSiguiente();
		}
	}
	return grupos;
}
Grupo* ListaGrupo::getGrupoPorPorfe(string id) {
	if (primero != NULL) {
		actual = primero;
		while (actual != NULL && actual->getElemento()->getProfesor()->getId() != id)
			actual = actual->getSiguiente();
		if (actual == NULL)
			return NULL;
		else
			return actual->getElemento();
	}

}
/*
ListaGrupo* ListaGrupo::getGruposPorEstudiante(string id) {
	ListaGrupo* grupos = new ListaGrupo();
	actual = primero;
	while (actual != NULL && actual->getSiguiente() != NULL) {
		if (actual->getElemento()->)
	}
}*/

Grupo* ListaGrupo::getGrupoPorNum(int num) {
	Grupo* Grupo = NULL;
	if (primero != NULL) {
		actual = primero;
		while (actual != NULL && actual->getElemento()->getNumeroGrupo() != num)
			actual = actual->getSiguiente();
		if (actual != NULL)
			Grupo = actual->getElemento();
	}
	return Grupo;
}

Grupo* ListaGrupo::getGrupoPos(int pos) {
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

bool ListaGrupo::vacio() {
	return primero == NULL;
}

string ListaGrupo::toString() {
	stringstream s;
	actual = primero;
	int pos = 0;
	while (actual != NULL) {
		s << pos << "- " << actual->getElemento()->toString();
		actual = actual->getSiguiente();
		pos++;
	s << endl;
	}
	return s.str();
}