#include "Interfaz.h"

//Inicio
void Interfaz::start(){
	ListaProfesor* ListProf = new ListaProfesor;
	ListaEstudiante* ListEst = new ListaEstudiante;
	ListaPeriodo* ListPer = new ListaPeriodo;
	ListaCurso* ListCur = new ListaCurso;
	ListaGrupo* ListGru = new ListaGrupo;
	ListaMatricula* ListMat = new ListaMatricula;

	cargadoDatos(ListCur, ListEst, ListGru, ListPer, ListProf);

	int opcion = -1;
	do {
		opcion = -1;
		while (opcion < 0 || opcion > 5) {
			menuPrincipal(opcion);
		}
		int opcion2 = -1;
		switch (opcion) {
		case 1:
		{
			//Submenu Administracion
			while (opcion2 < 0 || opcion > 6) {
				submenuAdministracion(opcion2);
			}
			int opcion3 = -1;
			system("cls");
			switch (opcion2) {
			case 1:
			{
				ingresarProfe(ListProf);
				break;
			}
			case 2:
			{
				ingresarEstudiante(ListEst);
				break;
			}
			case 3:
			{
				ingresarPeriodo(ListPer);
				break;
			}
			case 4:
			{
				ingresarCurso(ListCur);
				break;
			}
			case 5:
			{
				ingresarGrupo(ListGru, ListCur, ListPer);
				break;
			}
			case 6:
			{
				asignarProfe(ListGru, ListProf);
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
				submenuMatricula(opcion2);
			}
			int opcion3 = -1;
			system("cls");
			switch (opcion2) {
			case 1:
			{
				matricularEstudiante(ListGru, ListEst, ListMat);
				break;
			}
			case 2:
			{
				desmatricularEstudiante(ListEst);
				break;
			}
			break;
			}
			system("pause");
			break;
		}
		case 3: {
			//Submenu Busquedas e Informes
			while (opcion2 < 0 || opcion2 > 6) {
				submenuBusquedas(opcion2);
			}
			system("cls");
			switch (opcion2) {
			case 1:
			{
				informeProfesores(ListProf);
				break;
			}
			case 2:
			{
				informeEstudiantes(ListEst);
				break;
			}
			case 3:
			{
				informeCursos(ListEst);
				break;
			}
			case 4:
			{
				informeProfeEspecifico(ListProf, ListGru);
				break;
			}
			case 5:
			{
				informePeriodosHabilitados(ListPer);
				break;
			}
			case 6:
			{
				informeGrupoEspecifico(ListCur, ListGru);
				break;
			}
			break;
			}
			system("pause");
			break;
		}
		case 4: {
			guardadoDatos(ListCur, ListEst, ListGru, ListPer, ListProf);
			system("pause");
			break;
		}
		}
	} while (opcion != 5);

	despedida();
}
void Interfaz::menuPrincipal(int& opcion){
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
void Interfaz::despedida(){
	cout << "Gracias por usar el programa. \n";
}

//Submenus
void Interfaz::submenuAdministracion(int& opcion2){
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
void Interfaz::submenuMatricula(int& opcion2){
	system("cls");
	cout << "Submenu de matricula. \n"
		<< "\t(1) Matricular Estudiante \n"
		<< "\t(2) Desmatricular Estudiante \n"
		<< "\t(0) Regresar al menu Principal \n\n"
		<< "Ingrese una opcion: ";
	cin >> opcion2;
}
void Interfaz::submenuBusquedas(int& opcion2){
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

//Datos
void Interfaz::guardadoDatos(ListaCurso* ListCur, ListaEstudiante* ListEst, ListaGrupo* ListGru, ListaPeriodo* ListPer, ListaProfesor* ListProf){
	ListCur->ingresarLista("ListaCursos.txt");
	ListEst->ingresarLista("ListaEst.txt");
	ListGru->ingresarLista("ListaGrupo.txt");
	ListPer->ingresarLista("ListaPer.txt");
	ListProf->ingresarLista("ListaProf.txt");
	cout << "Realizado con exito. " << endl;
}
void Interfaz::cargadoDatos(ListaCurso* ListCur, ListaEstudiante* ListEst, ListaGrupo* ListGru, ListaPeriodo* ListPer, ListaProfesor* ListProf){
	ListCur->sacarLista("ListaCursos.txt");
	ListEst->sacarLista("ListaEst.txt");
	ListGru->sacarLista("ListaGrupo.txt");
	ListPer->sacarLista("ListaPer.txt");
	ListProf->sacarLista("ListaProf.txt");
}

//Dentro de administracion
void Interfaz::ingresarProfe(ListaProfesor* ListProf){
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
}
void Interfaz::ingresarEstudiante(ListaEstudiante* ListEst){
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
}
void Interfaz::ingresarPeriodo(ListaPeriodo* ListPer){
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
}
void Interfaz::ingresarCurso(ListaCurso* ListCur){
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
}
void Interfaz::ingresarGrupo(ListaGrupo* ListGru, ListaCurso* ListCur, ListaPeriodo* ListPer){
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
}
void Interfaz::asignarProfe(ListaGrupo* ListGru, ListaProfesor* ListProf){
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
}

//Dentro de matricula
void Interfaz::matricularEstudiante(ListaGrupo* ListGru, ListaEstudiante* ListEst, ListaMatricula* ListMat){
	//Matricular Estudiante
	int periodo;
	int pos;
	//Matricular Estudiante
	cout << "Matricular un estudiante en un curso.\n";
	cout << "Eliga el grupo. \n"
		<< ListGru->toString()
		<< "Ingrese la posicion del grupo: ";
	cin >> pos;
	Grupo* gru = ListGru->getGrupoPos(pos);
	cout << "Eliga el estudiante. \n"
		<< ListEst->toString()
		<< "Ingrese la posicion del estudiante: ";
	cin >> pos;
	Estudiante* est = ListEst->getEstudiantePos(pos);
	est->matricularGrupo(gru);
	Matricula* mat = new Matricula(gru, est);
	ListMat->ingresarMatricula(mat);
	cout << "Realizado con exito. \n";
}
void Interfaz::desmatricularEstudiante(ListaEstudiante* ListEst){
	cout << "Desmatricular un estudiante de un curso. \n\n";
	cout << "Eliga el estudiante. \n"
		<< ListEst->toString()
		<< "Ingrese la posicion del estudiante: ";
	string id;
	int num;
	cin.ignore();
	getline(cin, id);
	Estudiante* est = ListEst->getEstudiantePorId(id);
	cout << est->getGruposMatriculados()->toString() << endl;
	cout << "Ingrese el numero del grupo del cual desea desmatricular: ";
	cin >> num;
	est->anularGrupo(est->getGruposMatriculados()->getGrupoPorNum(num));
	cout << "Realizado con exito. \n";
}

//Dentro de busquedas
void Interfaz::informeProfesores(ListaProfesor* ListProf){
	//Informe Profesores Registrados
	cout << "Informe Profesores Registrados \n\n"
		<< ListProf->toString() << endl;
}
void Interfaz::informeEstudiantes(ListaEstudiante* ListEst){
	//Informe Estudiantes Registrados
	cout << "Informe Estudiantes Registrados \n\n"
		<< ListEst->toString() << endl;
}
void Interfaz::informeCursos(ListaEstudiante* ListEst){
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
}
void Interfaz::informeProfeEspecifico(ListaProfesor* ListProf, ListaGrupo* ListGru){
	//Informe Profesor Especifico
	cout << "Eliga al profesor el cual desea ver: \n Ingrese la cedula\n";
	string id;
	cout << ListProf->toString() << endl;
	cin.ignore();
	getline(cin, id);
	ListProf->getProfesorPorId(id);
	Grupo* grup = ListGru->getGrupoPorPorfe(id);
	if (grup != NULL) {
		cout << "Cursos Impartidos por el profesor: \n";
		cout << grup->getCurso()->toString() << endl;
		cout << "Grupos Impartidos por el profesor: \n";
		cout << grup->toString();
	}
}
void Interfaz::informePeriodosHabilitados(ListaPeriodo* ListPer){
	//Informe Periodos Habilitados para el Annio
	cout << "Informe Periodos Habilitados Para el Annio \n \n"
		<< ListPer->toString() << endl;
}
void Interfaz::informeGrupoEspecifico(ListaCurso* ListCur, ListaGrupo* ListGru){
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

}