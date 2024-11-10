#pragma once
#include "ListaEstudiante.h"
#include "ListaGrupo.h"
#include "ListaProfesor.h"
#include "ListaPeriodo.h"
#include "ListaCurso.h"
#include "ListaMatricula.h"

#include <iostream>
#include <fstream>
using namespace std;

class Interfaz {
public:
	//Inicio
	static void start();
	static void menuPrincipal(int&);
	static void despedida();

	//Submenus
	static void submenuAdministracion(int&);
	static void submenuMatricula(int&);
	static void submenuBusquedas(int&);

	//Datos
	static void guardadoDatos(ListaCurso*, ListaEstudiante*, ListaGrupo*, ListaPeriodo*, ListaProfesor*);
	static void cargadoDatos(ListaCurso*, ListaEstudiante*, ListaGrupo*, ListaPeriodo*, ListaProfesor*);

	//Dentro de administracion
	static void ingresarProfe(ListaProfesor*);
	static void ingresarEstudiante(ListaEstudiante*);
	static void ingresarPeriodo(ListaPeriodo*);
	static void ingresarCurso(ListaCurso*);
	static void ingresarGrupo(ListaGrupo*, ListaCurso*, ListaPeriodo*);
	static void asignarProfe(ListaGrupo*, ListaProfesor*);

	//Dentro de matricula
	static void matricularEstudiante(ListaGrupo*, ListaEstudiante*, ListaMatricula*);
	static void desmatricularEstudiante(ListaEstudiante*);

	//Dentro de busquedas
	static void informeProfesores(ListaProfesor*);
	static void informeEstudiantes(ListaEstudiante*);
	static void informeCursos(ListaEstudiante*);
	static void informeProfeEspecifico(ListaProfesor*, ListaGrupo*);
	static void informePeriodosHabilitados(ListaPeriodo*);
	static void informeGrupoEspecifico(ListaCurso*, ListaGrupo*);
};

