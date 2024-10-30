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