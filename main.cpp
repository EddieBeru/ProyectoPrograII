#include <iostream>
#include <fstream>
#include "Estudiante.h"
#include "ListaCurso.h"
using namespace std;

int main() {
	Curso* c = new Curso("1234", "1234", 1234, 0.0, false);
	Curso* h = new Curso("12345", "12345", 12345, 1.0, true);
	ListaCurso* lc = new ListaCurso();
	lc->ingresarCurso(c);
	cout << lc->toString() << endl;
	lc ->modificarCurso(c, h);
	cout << lc->toString() << endl;
	lc->eliminarCurso(h);
	cout << lc->toString() << endl;

	Estudiante* est = new Estudiante("1234", "1234", "7654", 0, "1212");

	string conf;
	while (conf != "No se me va a olvidar"){
		cout << "Nunca se olvide de usar getline(), escriba 'No se me va a olvidar' para confirmar: ";
		getline(cin, conf);
	}
	cin.ignore();

	ofstream of("testing.txt", ios::app);
	of.write((char*)&est, sizeof(est));
	of.close();

	/* Esto tira error ajjajdshabsi
	ifstream i("testing.txt");
	i.read((char*)&est, sizeof(est));
	i.close();
	*/
	
	delete est;
	system("pause");
	return 0;
}