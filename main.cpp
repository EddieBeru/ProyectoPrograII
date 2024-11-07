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
	int opcion = -1;
	do {
		while (opcion < 0 || opcion > 5) {
			system("cls");
			cout << "Insertar bienvenida general aca \n"
				<< "(1) - Submenu Administracion \n"
				<< "(2) - Submenu Matricula \n"
				<< "(3) - Submenu Busquedas e Informes \n"
				<< "(4) - Guardar los Datos en Archivos \n"
				<< "(5) - Salir \n"
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
				cout << "Otra bienvenida mas que hacer \n"
					<< "(1) Ingresar Profesor \n"
					<< "(2) Ingresar Estudiante \n"
					<< "(3) Ingresar Bloque o Periodo \n"
					<< "(4) Ingresar Curso \n"
					<< "(5) Ingresar Grupo \n"
					<< "(6) Asignar Profesor a Grupo \n"
					<< "(0) Regresar al Menu Principal \n"
					<< "Ingrese una opcion: ";
				cin >> opcion2;
			}
			int opcion3 = -1;
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
				cout << "Ingrese el curso del grupo: ";
				//Listar cursos
				cout << ListCur->toString() << endl;
				string cursoId;
				cout << "Ingrese el id del curso: ";
				cin.ignore();
				getline(cin, cursoId);
				curso = ListCur->getCursoPorId(cursoId);
				cout << "Crear el horario del grupo: ";
				//Crear horario
				int horaInicio, horaFinal, diasSemana;
				cout << "Ingrese la hora de inicio: ";
				cin >> horaInicio;
				cout << "Ingrese la hora final: ";
				cin >> horaFinal;
				cout << "Ingrese los dias de la semana: ";
				cin >> diasSemana;
				horario = new Horario(horaInicio, horaFinal, diasSemana);
				cout << "Ingrese el periodo del grupo: ";
				//Listar periodos
				cout << ListPer->toString() << endl;
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
				cout << "Inserte bienvenida aca \n"
					<< "(1) Matricular Estudiante \n"
					<< "(2) Desmatricular Estudiante \n"
					<< "(0) Regresar al menu Principal \n"
					<< "Ingrese una opcion: ";
				cin >> opcion2;
			}
			int opcion3 = -1;
			switch (opcion2) {
			case 1:
			{
				//Matricular Estudiante
			}
			break;
			case 2:
			{
				//Desmatricular Estudiante
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
				cout << "Inserte bienvenida aca \n"
					<< "(1) Informe Profesores Registrados \n"
					<< "(2) Informe Estudiantes Registrados \n"
					<< "(3) Informe Cursos Matriculados por un Estudiante \n"
					<< "(4) Informe Profesor Especifico \n"
					<< "(5) Informe Periodos Habilitados para el Annio \n"
					<< "(6) Informe Grupo Especifico \n"
					<< "(0) Regresar al Menu Principal \n"
					<< "Ingrese una opcion: ";
				cin >> opcion2;
			}
			switch (opcion2) {
			case 1:
			{
				//Informe Profesores Registrados
				cout << "Informe Profesores Registrados \n\n"
					<< ListProf->toString() << endl;
			}
			break;
			case 2:
			{
				//Informe Estudiantes Registrados
				cout << "Informe Estudiantes Registrados \n\n"
					<< ListEst->toString() << endl;
			}
			break;
			case 3:
			{
				//Informe Cursos Matriculados por un Estudiante
				cout << "Informe Cursos Matriculados por un Estudiante \n\n"
					<< "Ingrese el id del estudiante: ";
				string id;
				cin.ignore();
				getline(cin, id);
				Estudiante* est = ListEst->getEstudiantePorId(id);
				cout << est->getGruposMatriculados()->toString() << endl;
			}
			break;
			case 4:
				//Informe Profesor Especifico
				break;
			case 5:
				//Informe Periodos Habilitados para el Annio
				break;
			case 6:
				//Informe Grupo Especifico
				break;
				break;
			}
			system("pause");
			break;

		}
		}
	} while (opcion != 5);
	
	//Crear Cosos
	ListaProfesor* L1=new ListaProfesor;
	ListaEstudiante* E1 = new ListaEstudiante;
	ListaPeriodo* P1 = new ListaPeriodo;
	ListaCurso* C1 = new ListaCurso;
	ListaGrupo* G1 = new ListaGrupo;
	Profesor* p1 = new Profesor("luis", "nose", 12, "tampoco", "menos");
	Profesor* p2 = new Profesor("mig", "nose", 45, "tampoco", "menos");
	Profesor* p3 = new Profesor("pedro", "nose", 32, "tampoco", "menos");
	L1->ingresarProfesor(p1);
	L1->ingresarProfesor(p2);
	L1->ingresarProfesor(p3);
	cout<<L1->toString() << endl<<endl<<endl;
	L1->ingresarLista("ListaProf.txt"); //se mete normal
	L1->sacarLista("ListaProf.txt");// hay uno vacio al final falta quitarlo
	cout << "AQUIIIIII\n\n";
	cout<<L1->toString() << endl << endl << endl;

	Estudiante* e1 = new Estudiante("jose", "nose", "nose", 12, "nose");
	Estudiante* e2 = new Estudiante("maria", "nose2", "nose", 13, "correo");
	Estudiante* e3 = new Estudiante("carlos", "nose3", "nose", 14, "correo");
	Estudiante* e4 = new Estudiante("ana", "nose4", "nose", 15, "correo");
	E1->ingresarEstudiante(e1);
	E1->ingresarEstudiante(e2);
	E1->ingresarEstudiante(e3);
	E1->ingresarEstudiante(e4);
	cout << E1->toString() << endl << endl << endl;
	cout << "AAAQUIIIIII\n\n";
	E1->ingresarLista("ListaEst.txt");//Entonces hay que cambiar este por el normal :)
	E1->sacarLista("ListaEst.txt");



	Periodo* pe1 = new Periodo(1);
	Periodo* pe2 = new Periodo(2);
	Periodo* pe3 = new Periodo(3);
	Periodo* pe4 = new Periodo(4);
	P1->ingresarPeriodo(pe1);
	P1->ingresarPeriodo(pe2);
	P1->ingresarPeriodo(pe3);
	P1->ingresarPeriodo(pe4);
	cout << P1->toString() << endl << endl << endl;
	string archivo = "archivo.txt";


	Curso* c1 = new Curso("Ingles", "nose", 2, 2.3, true);
	Curso* c2 = new Curso("Matematicas", "nose2", 3, 3.5, true);
	Curso* c3 = new Curso("Programacion", "nose3", 4, 4.0, true);
	Curso* c4 = new Curso("Fisica", "nose4", 3, 3.0, false);
	C1->ingresarCurso(c1);
	C1->ingresarCurso(c2);
	C1->ingresarCurso(c3);
	C1->ingresarCurso(c4);
	cout << C1->toString() << endl << endl << endl;


	Horario* h1=new Horario(12, 1, 6);
	Horario* h2 = new Horario(14, 2, 8);
	Horario* h3 = new Horario(16, 3, 10);
	Horario* h4 = new Horario(18, 4, 12);
	Grupo* g1 = new Grupo(12, 13, 14, h1, c1, pe1);
	Grupo* g2 = new Grupo(15, 16, 17, h2, c2, pe2);
	Grupo* g3 = new Grupo(18, 19, 20, h3, c3, pe3);
	Grupo* g4 = new Grupo(21, 22, 23, h4, c4, pe4);
	g2->setProfesor(L1->getProfesorEspecifico(2));//se le asigna un profesor al grupo con su posicion en la lista
	//empezando en 1

	G1->ingresarGrupo(g1);
	G1->ingresarGrupo(g2);  
	G1->ingresarGrupo(g3);
	G1->ingresarGrupo(g4);
	cout << G1->toString() << endl << endl << endl;



	//Matricula 
	cout << "MATRICULAAAA"<<endl;
	ListaMatricula* M1=new ListaMatricula;
	Matricula* mat = new Matricula(pe1, c1, g1, e1);
	Matricula* mat1 = new Matricula(pe1, c1, g1, e1);
	Matricula* mat2 = new Matricula(pe1, c1, g1, e1);
	Matricula* mat3 = new Matricula(pe1, c1, g1, e1);

	M1->ingresarMatricula(mat);
	M1->ingresarMatricula(mat1);
	M1->ingresarMatricula(mat2);
	M1->ingresarMatricula(mat3);
	cout<<M1->getDescuento(e1)<<"%" << endl;
	cout<<M1->factura(e1);















	//Curso* c = new Curso("Ingles", "1234", 123, 0.0, false);
	//Curso* h = new Curso("Espanol", "12345", 456, 1.0, true);
	//ListaCurso* lc = new ListaCurso();
	//lc->ingresarCurso(c);
	//cout << lc->toString() << endl;
	//lc ->modificarCurso(c, h);
	//cout << lc->toString() << endl;
	//lc->eliminarCurso(h);
	//cout << lc->toString() << endl;

	//Estudiante est("pedro", "123", "Docotor", 456789, "correogaigai");

	////string conf;
	////while (conf != "No se me va a olvidar"){
	//	//cout << "Nunca se olvide de usar getline(), escriba 'No se me va a olvidar' para confirmar: ";
	//	//getline(cin, conf);
	////}
	////cin.ignore();

	//ofstream Estudiantes("testing.txt", ios::app);
	//Estudiantes.write((char*)&est, sizeof(est));
	//Estudiantes.close();

	//ifstream Est("testing.txt");
	//if (Est) {
	//	Estudiante estu;
	//	Est.read((char*)&estu, sizeof(estu));
	//	while (!Est.eof()) {
	//		cout<<estu.toString()<<endl;
	//		Est.read((char*)&estu, sizeof(estu));
	//	}
	//}
	//Est.close();
	//
	//delete c;
	//delete h;
	//system("pause");
	
	return 0;
}