#include <iostream>
#include <fstream>
#include "Estudiante.h"
using namespace std;

int main() {
	Estudiante est("", "", "", 0, "");

	string conf;
	while (conf != "No se me va a olvidar"){
		cout << "Nunca se olvide de usar getline(), escriba 'No se me va a olvidar' para confirmar: ";
		getline(cin, conf);
	}
	cin.ignore();

	ofstream of("testing.txt", ios::app);
	of.write((char*)&est, sizeof(est));
	
	ifstream i("testing.txt");
	i.read((char*)&est, sizeof(est));


	system("pause");
	return 0;
}