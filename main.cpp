#include <iostream>
#include <fstream>
#include "ListaEstudiante.h"
#include "ListaGrupo.h"
#include "ListaProfesor.h"
#include "ListaPeriodo.h"
#include "ListaCurso.h"
#include "ListaMatricula.h"
using namespace std;

int main() {
	ListaProfesor* ListProf = new ListaProfesor;
	ListaEstudiante* ListEst = new ListaEstudiante;
	ListaPeriodo* ListPer = new ListaPeriodo;
	ListaCurso* ListCur = new ListaCurso;
	ListaGrupo* ListGru = new ListaGrupo;
	ListaMatricula* ListMat = new ListaMatricula;

	ListCur->sacarLista("ListaCursos.txt");
	ListEst->sacarLista("ListaEst.txt");
	ListGru->sacarLista("ListaGrupo.txt");
	ListPer->sacarLista("ListaPer.txt");
	ListProf->sacarLista("ListaProf.txt");

	int opcion = -1;
	do {
		opcion = -1;
		while (opcion < 0 || opcion > 5) {
			system("cls");
			cout << "Bienvenido a la Academia Virtual Eureka AI School. \n"
				<< "\t(1) - Submenu Administracion \n"
				<< "\t(2) - Submenu Matricula \n"
				<< "\t(3) - Submenu Busquedas e Informes \n"
				<< "\t(4) - Guardar los Datos en Archivos \n"
				<< "\t(5) - Salir \n\n"
				<< "Ingrese una opcion: ";
			cin >> opcion;
		}
		int opcion2 = -1;
		switch (opcion) {
		case 1:
		{
			//Submenu Administracion
			while (opcion2 < 0 || opcion > 6) {
				system("cls");
				cout << "Submenu de administracion. \n"
					<< "\t(1) Ingresar Profesor \n"
					<< "\t(2) Ingresar Estudiante \n"
					<< "\t(3) Ingresar Bloque o Periodo \n"
					<< "\t(4) Ingresar Curso \n"
					<< "\t(5) Ingresar Grupo \n"
					<< "\t(6) Asignar Profesor a Grupo \n"
					<< "\t(0) Regresar al Menu Principal \n\n"
					<< "Ingrese una opcion: ";
				cin >> opcion2;
			}
			int opcion3 = -1;
			system("cls");
			switch (opcion2) {
			case 1:
			{
				//Ingresar Profesor
					string nombre, id, email, gradoAcademico;
					int numero;
				//Recoleccion de datos
					cout << "Ingresar profesor. \n\n"
						<< "Ingrese el nombre del profesor: ";
					cin.ignore();
					getline(cin, nombre);
					cout << "Ingrese el id del profesor: ";
					getline(cin, id);
					cout << "Ingrese el numero del profesor: ";
					cin >> numero;
					cout << "Ingrese el email del profesor: ";
					cin.ignore();
					getline(cin, email);
					cout << "Ingrese el grado academico del profesor: ";
					getline(cin, gradoAcademico);
				//Creacion e ingreso
					Profesor* profesor = new Profesor(nombre, id, numero, email, gradoAcademico);
					if (ListProf->ingresarProfesor(profesor))
						cout << "Realizado con exito. \n";
					else cout << "Ocurrio un error. \n";
				break;
			}
			case 2:
			{
				//Ingresar Estudiante
					string nombre, id, especialidad, email;
					int numero;
				//Recoleccion de datos
					cout << "Ingresar estudiante. \n\n"
						<< "Ingrese el nombre del estudiante: ";
					cin.ignore();
					getline(cin, nombre);
					cout << "Ingrese el id del estudiante: ";
					getline(cin, id);
					cout << "Ingrese la especialidad del estudiante: ";
					getline(cin, especialidad);
					cout << "Ingrese el numero del estudiante: ";
					cin >> numero;
					cout << "Ingrese el email del estudiante: ";
					cin.ignore();
					getline(cin, email);
				//Creacion e ingreso
				Estudiante* estudiante = new Estudiante(nombre, id, especialidad, numero, email);
					if (ListEst->ingresarEstudiante(estudiante))
						cout << "Realizado con exito. \n";
					else cout << "Ocurrio un error. \n";
				break;
			}
			case 3:
			{
				//Ingresar Bloque o Periodo
					int periodoNum;
				//Recoleccion de datos
					cout << "Ingresar periodo. \n\n"
						<< "Ingrese el numero del periodo: ";
					cin >> periodoNum;
				//Creacion e ingreso
					Periodo* periodo = new Periodo(periodoNum);
					if (ListPer->ingresarPeriodo(periodo))
						cout << "Realizado con exito. \n";
					else cout << "Ocurrio un error. \n";
				break;
			}
			case 4:
			{
				//Ingresar Curso
					string nombre, id;
					int horas;
					float precio;
					bool estado;
				//Recoleccion de datos
					cout << "Ingresar curso. \n\n"
						<< "Ingrese el nombre del curso: ";
					cin.ignore();
					getline(cin, nombre);
					cout << "Ingrese el id del curso: ";
					getline(cin, id);
					cout << "Ingrese las horas del curso: ";
					cin >> horas;
					cout << "Ingrese el precio del curso: ";
					cin >> precio;
					cout << "Ingrese el estado del curso (1 para disponible, 0 para no disponible): ";
					cin >> estado;
				//Creacion e ingreso
					Curso* curso = new Curso(nombre, id, horas, precio, estado);
					if (ListCur->ingresarCurso(curso))
						cout << "Realizado con exito. \n";
					else cout << "Ocurrio un error. \n";
				break;
			}
			case 5:
			{
				//Ingresar Grupo
					int numero, capacidad, cantidad = 0;
					Curso* curso;
					Horario* horario;
					Periodo* periodo;
				//Recoleccion de datos
					cout << "Ingresar grupo. \n\n"
						<< "Ingrese el numero del grupo: ";
					cin >> numero;
					cout << "Ingrese la capacidad del grupo: ";
					cin >> capacidad;
					cout << "Ingrese el curso del grupo.\n";
				//Listar cursos
					cout << ListCur->toString();
					string cursoId;
					cout << "Ingrese el id del curso: ";
					cin.ignore();
					getline(cin, cursoId);
					curso = ListCur->getCursoPorId(cursoId);
					cout << "Crear el horario del grupo. \n";
				//Crear horario
					int horaInicio, horaFinal, diasSemana;
					cout << "Ingrese la hora de inicio: ";
					cin >> horaInicio;
					cout << "Ingrese la hora final: ";
					cin >> horaFinal;
					cout << "Ingrese los dias de la semana: ";
					cin >> diasSemana;
					horario = new Horario(horaInicio, horaFinal, diasSemana);
					cout << "Ingrese el periodo del grupo. \n";
				//Listar periodos
					cout << ListPer->toString();
					int periodoNum;
					cout << "Ingrese el numero del periodo: ";
					cin >> periodoNum;
					periodo = ListPer->getPeriodoPorNum(periodoNum);
				//Creacion e ingreso
					Grupo* grupo = new Grupo(numero, capacidad, cantidad, horario, curso, periodo);
					if (ListGru->ingresarGrupo(grupo))
						cout << "Realizado con exito \n.";
					else cout << "Ocurrio un error. \n";
				break;
			}
			case 6:
			{
				//Asignar Profesor a Grupo
					Grupo* grupoElegido;
					Profesor* profesorElegido;
				//Recoleccion de datos
					cout << "Ingrese el grupo a cambiar de profesor: \n";
				//Listar grupos
					cout << ListGru->toString() << endl;
					int grupoNum;
					cout << "Ingrese el numero del grupo: ";
					cin >> grupoNum;
					grupoElegido = ListGru->getGrupoPorNum(grupoNum);
					cout << "Ingrese el profesor a asignar al grupo: \n";
				//Listar profesores
					cout << ListProf->toString() << endl;
					string profesorId;
					cout << "Ingrese el id del profesor: ";
					cin.ignore();
					getline(cin, profesorId);
					profesorElegido = ListProf->getProfesorPorId(profesorId);
					grupoElegido->setProfesor(profesorElegido);
					cout << "Realizado con exito. \n";
				break;
			}
			}
			system("pause");
			break;
		}
		case 2:
		{
			// Submenu Matricula
			while (opcion2 < 0 || opcion2 > 2) {
				system("cls");
				cout << "Submenu de matricula. \n"
					<< "\t(1) Matricular Estudiante \n"
					<< "\t(2) Desmatricular Estudiante \n"
					<< "\t(0) Regresar al menu Principal \n\n"
					<< "Ingrese una opcion: ";
				cin >> opcion2;
			}
			int opcion3 = -1;
			system("cls");
			switch (opcion2) {
			case 1:
			{
				//Matricular Estudiante
				int opcion = 1;
					int periodo;
					int pos;
        
				while (opcion != 0) {
				//Matricular Estudiante
					cout << "Eliga el grupo. \n"
						<< ListGru->toString()
						<< "Ingrese la posicion del grupo: ";
					cin >> pos;
					Grupo* gru=ListGru->getGrupoPos(pos);
					cout << "Eliga el estudiante. \n"
						<< ListEst->toString()
						<< "Ingrese la posicion del estudiante: ";
					cin >> pos;
					Estudiante* est = ListEst->getEstudiantePos(pos);
					est->matricularGrupo(gru);
					Matricula* mat = new Matricula(gru, est);
					ListMat->ingresarMatricula(mat);
				cout << ListMat->factura(est) << endl << endl;
					cout << "Realizado con exito, digite 1 si desea hacer otra matricula; de otro modo, digite 0: ";
          cin >> opcion;
				}
					break;
			}
			case 2:
			{
				//Desmatricular Estudiante
				cout << "Cursos Matriculados por un Estudiante \n\n"
					<< "Ingrese el id del estudiante: ";
				cout << ListEst->toString() << endl;
				string id;
				int num;
				cin.ignore();
				getline(cin, id);
				Estudiante* est = ListEst->getEstudiantePorId(id);
				cout << est->getGruposMatriculados()->toString() << endl;
				cout << "Ingrese el numero del grupo del cual desea desmatricular: \n";
				cin >> num;
				est->anularGrupo(est->getGruposMatriculados()->getGrupoPorNum(num));
			}
			break;
			}
			system("pause");
			break;
		}
		case 3: {
			//Submenu Busquedas e Informes
			while (opcion2 < 0 || opcion2 > 6) {
				system("cls");
				cout << "Submenu de busquedas e informes. \n"
					<< "\t(1) Informe Profesores Registrados \n"
					<< "\t(2) Informe Estudiantes Registrados \n"
					<< "\t(3) Informe Cursos Matriculados por un Estudiante \n"
					<< "\t(4) Informe Profesor Especifico \n"
					<< "\t(5) Informe Periodos Habilitados para el Annio \n"
					<< "\t(6) Informe Grupo Especifico \n"
					<< "\t(0) Regresar al Menu Principal \n\n"
					<< "Ingrese una opcion: ";
				cin >> opcion2;
			}
			system("cls");
			switch (opcion2) {
			case 1:
			{
				//Informe Profesores Registrados
				cout << "Informe Profesores Registrados \n\n"
					<< ListProf->toString() << endl;
				break;
			}
			case 2:
			{
				//Informe Estudiantes Registrados
				cout << "Informe Estudiantes Registrados \n\n"
					<< ListEst->toString() << endl;
				break;
			}
			case 3:
			{
				//Informe Cursos Matriculados por un Estudiante
				cout << "Informe Cursos Matriculados por un Estudiante \n\n"
					<< "Elija al estudiante. \n "
					<< ListEst->toString()
					<< "Seleccione escribiendo su id: ";
				string id;
				cin.ignore();
				getline(cin, id);
				Estudiante* est = ListEst->getEstudiantePorId(id);
				cout << est->getGruposMatriculados()->toString() << endl;
				break;
			}
			case 4:
			{
				//Informe Profesor Especifico
				cout << "Eliga al profesor el cual desea ver: \n Ingrese la cedula\n";
				string id;
				cout << ListProf->toString() << endl;
				getline(cin, id);
				ListProf->getProfesorPorId(id);
				Grupo* grup = ListGru->getGrupoPorPorfe(id);
				cout << "Cursos Impartidos por el profesor: \n";
				cout << grup->getCurso()->toString() << endl;
				cout << "Grupos Impartidos por el profesor: \n";
				cout << grup->toString();
				break;
			}
			case 5:
			{
				//Informe Periodos Habilitados para el Annio
				cout << "Informe Periodos Habilitados Para el Annio \n \n"
					<< ListPer->toString() << endl;
				break;
			}
			case 6:
			{
				//Informe Grupo Especifico
				cout << "Informe Grupo Especifico \n \n"
					<< "Elije un curso"
					<< ListCur->toString()
					<< "Ingrese el id del curso seleccionado: ";
				string curId;
				cin.ignore();
				getline(cin, curId);
				Curso* cur = ListCur->getCursoPorId(curId);
				ListaGrupo* grupos = ListGru->getGruposPorCurso(cur);
				cout << "Elije un grupo"
					<< grupos->toString()
					<< "Ingrese el numero del grupo seleccionado: ";
				int gruInd;
				cin >> gruInd;
				Grupo* grup = grupos->getGrupoPorNum(gruInd);
				cout << grup->toString() << endl;
				break;
			}
				break;
			}
			system("pause");
			break;
		}
		case 4: {
			ListCur->ingresarLista("ListaCursos.txt");
			ListEst->ingresarLista("ListaEst.txt");
			ListGru->ingresarLista("ListaGrupo.txt");
			ListPer->ingresarLista("ListaPer.txt");
			ListProf->ingresarLista("ListaProf.txt");
			cout << "Realizado con exito. " << endl;
			system("pause");
			break;
		}
		case 4: {
			ListCur->ingresarLista("ListaCursos.txt");
			ListEst->ingresarLista("ListaEst.txt");
			ListGru->ingresarLista("ListaGrupo.txt");
			ListPer->ingresarLista("ListaPer.txt");
			ListProf->ingresarLista("ListaProf.txt");
		}
			  break;
		}
	} while (opcion != 5);

	return 0;
}